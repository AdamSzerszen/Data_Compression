#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class CEncodedContent
{
private:
    vector<string>* _dictionary;
    vector<int>* _encodedText;
public:
    CEncodedContent(vector<string>* dictionary, vector<int>* encodedText);
    vector<string>* GetDictionary(void)const;
    vector<int>* GetEncodedText(void)const;
    ~CEncodedContent();
};

