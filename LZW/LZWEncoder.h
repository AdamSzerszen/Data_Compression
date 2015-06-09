#pragma once
#include <string>
#include <vector>
#include "EncodedContent.h"

using std::string;
using std::vector;

class CLZWEncoder
{
private:
    vector<string>* _dictionary;
    vector<int>* _indexes;
    string _lastSeries;
    string _currentSeries;
    string _sumOfSeries;
    string _textToEncode;

    CLZWEncoder();
    void loadText(string text);
    void setLastSeries(string series);
    void initiatingAlphabet(void);
    void addToDictionary(string series);
    int findIndex(string series)const;
    void addIndex(int index);
    void foundNewSeries(string series, string currentSeries, int index);
    void foundExistingSeries(string sumOfSeries);
    void loadSymbol(string symbol, bool lastSymbol);
    void addLastSeries(string symbol);
public:
    static CEncodedContent* Encode(string fileAsString);
    ~CLZWEncoder();
};

