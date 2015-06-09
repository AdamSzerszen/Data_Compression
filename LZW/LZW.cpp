#include "LZW.h"


CLZW::CLZW()
{
}

string CLZW::loadFile(const string fileName)
{
    std::ifstream is(fileName, std::ifstream::binary);

    // Find the length of the file
    is.seekg(0, is.end);
    std::streampos length = is.tellg();
    is.seekg(0, is.beg);

    // Create a vector to read it into
    vector<unsigned char> bytes(length);

    // Actually read data
    is.read((char *)&bytes[0], length);

    // Close the file explicitly, since we're finished with it
    is.close();
    string str(bytes.begin(), bytes.end());
    return str;
}

void CLZW::saveDictionary(vector<string> dictionary, const string output)
{
    std::ofstream ofstr(output, std::ios::binary);
    ofstr << dictionary.size();
    std::copy(dictionary.begin(), dictionary.end(), std::ostream_iterator<string>(ofstr, "\n"));
    ofstr.close();
}

vector<string>* CLZW::loadDictionary(const string dictionary)
{
    size_t size;
    std::ifstream ifstr(dictionary, std::ios::binary);
    ifstr >> size;
    vector<string> readedDictionary;
    readedDictionary.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        ifstr >> readedDictionary[i];
    }
    vector<string>* tempDictionary = new vector<string>();
    *tempDictionary = readedDictionary;
    return tempDictionary;
}

string CLZW::prepareEncodedFile(vector<int>* indexes)
{
    string encodedFile = "";
    for (auto it = indexes->begin(); it != indexes->end(); ++it)
    {
        encodedFile.append(CEliasEncoder::Encode(*it));
    }

    return encodedFile;
}

void CLZW::saveFile(const string output, vector<char>* content)const
{
    std::ofstream encodedFile;
    encodedFile.open(output);
    unsigned size = content->size();
    for (unsigned i = 0; i < size; i++)
    {
        encodedFile << content->at(i);
    }
    encodedFile.close();
    delete content;
}

void CLZW::Encode(const string input, const string output, const string dictionaryFile)
{
    auto encoder = new CLZW();
    auto textAsString = encoder->loadFile(input);
    auto encodedContent = CLZWEncoder::Encode(textAsString);
    auto encodedIndexes = encodedContent->GetEncodedText();
    encoder->saveDictionary(*encodedContent->GetDictionary(), dictionaryFile);
    auto encodedFile = encoder->prepareEncodedFile(encodedIndexes);
    auto preparedAscis = new vector<char>();
    CBinaryConverter::GetASCIS(encodedFile, preparedAscis);
    encoder->saveFile(output, preparedAscis);

    delete encoder;
    delete encodedContent;
}

void CLZW::Decode(const string input, const string output, const string dictionaryFile)
{
    auto decoder = new CLZW();
    auto dictionary = decoder->loadDictionary(dictionaryFile);
    auto rawFile = decoder->loadFile(input);
    auto indexes = new vector<int>();
    string binaryFile = "";
    for (unsigned i = 0; i < rawFile.length(); i++)
    {
        binaryFile.append(CBinaryConverter::CharToBinaryString(rawFile[i]));
    }
    while (binaryFile.length() > 2)
    {
        indexes->push_back(CEliasDecoder::Decode(&binaryFile));
    }

    std::ofstream decodedFile;
    decodedFile.open(output);
    
    for (unsigned i = 0; i < indexes->size(); i++)
    {
        decodedFile << dictionary->at(indexes->at(i));
    }
    decodedFile.close();
    delete dictionary;
    delete decoder;
}

CLZW::~CLZW()
{
}
