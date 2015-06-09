#pragma once
#include <string>
#include <fstream>
#include <bitset>
#include "LZWEncoder.h"
#include "EliasEncoder.h"
#include "EliasDecoder.h"

using std::string;
using std::bitset;

class CLZW
{
private:
    CLZW();
    string loadFile(const string fileName);
    void saveDictionary(vector<string> dictionary, const string output);
    vector<string>* loadDictionary(const string dictionary);
    string prepareEncodedFile(vector<int>* indexes);
    void saveFile(const string output, vector<char>* content)const;
public:
    static void Encode(const string input, const string output, const string dictionaryFile);
    static void Decode(const string input, const string output, const string dictionaryFile);
    ~CLZW();
};

