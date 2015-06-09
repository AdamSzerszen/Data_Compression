#include "LZWEncoder.h"


CLZWEncoder::CLZWEncoder() :
_dictionary(new vector<string>()),
_indexes(new vector<int>()),
_lastSeries(""),
_currentSeries(""),
_sumOfSeries(""),
_textToEncode("")
{
}

void CLZWEncoder::loadText(string text)
{
    _textToEncode = text;
}

void CLZWEncoder::setLastSeries(string series)
{
    _lastSeries = series;
}

void CLZWEncoder::initiatingAlphabet(void)
{
    for (unsigned i = 0; i < _textToEncode.length(); i++)
    {
        auto tempSeries = _textToEncode.substr(i, 1);
        if (std::find(_dictionary->begin(),
            _dictionary->end(),
            tempSeries) == _dictionary->end())
        {
            _dictionary->push_back(tempSeries);
        }
    }

    setLastSeries(_textToEncode.substr(0, 1));
}

void CLZWEncoder::addToDictionary(string series)
{
    _dictionary->push_back(series);
}

int CLZWEncoder::findIndex(string series)const
{
    for (unsigned i = 0; i < _dictionary->size(); i++)
    {
        if (_dictionary->at(i) == series)
        {
            return i;
        }
    }
    return 0;
}

void CLZWEncoder::addIndex(int index)
{
    _indexes->push_back(index);
}

void CLZWEncoder::foundNewSeries(string series, string currentSeries, int index)
{
    addIndex(index);
    _lastSeries = currentSeries;
    addToDictionary(series);
}

void CLZWEncoder::foundExistingSeries(string sumOfSeries)
{
    _lastSeries = sumOfSeries;
}

void CLZWEncoder::loadSymbol(string symbol, bool lastSymbol)
{
    int index;
    _currentSeries = symbol;
    _sumOfSeries = _lastSeries + _currentSeries;

    if (std::find(_dictionary->begin(), _dictionary->end(), _sumOfSeries) == _dictionary->end())
    {
        index = findIndex(_lastSeries);
        foundNewSeries(_sumOfSeries, _currentSeries, index);
    }
    else
    {
        if (lastSymbol)
        {
            index = findIndex(_sumOfSeries);
            addIndex(index);
        }
        else
        {
            foundExistingSeries(_sumOfSeries);
        }
    }
}

void CLZWEncoder::addLastSeries(string series)
{
    if (std::find(_dictionary->begin(), _dictionary->end(), series) == _dictionary->end())
    {

    }
}

CEncodedContent* CLZWEncoder::Encode(string fileAsString)
{
    auto encoder = new CLZWEncoder();
    encoder->loadText(fileAsString);
    encoder->initiatingAlphabet();

    int size = encoder->_textToEncode.length();
    for (unsigned i = 1; i < (unsigned)size; i++)
    {
        if (i == (unsigned)size - 1)
        {
            encoder->loadSymbol(encoder->_textToEncode.substr(i, 1), true);
        }
        else
        {
            encoder->loadSymbol(encoder->_textToEncode.substr(i, 1), false);
        }
    }

    auto encodedContent = new CEncodedContent(encoder->_dictionary, encoder->_indexes);

    delete encoder;
    return encodedContent;
}

CLZWEncoder::~CLZWEncoder()
{
}
