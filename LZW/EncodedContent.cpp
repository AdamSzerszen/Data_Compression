#include "EncodedContent.h"


CEncodedContent::CEncodedContent(vector<string>* dictionary, vector<int>* encodedText) :
_dictionary(dictionary),
_encodedText(encodedText)
{
}

vector<string>* CEncodedContent::GetDictionary(void)const
{
    return _dictionary;
}

vector<int>* CEncodedContent::GetEncodedText(void)const
{
    return _encodedText;
}

CEncodedContent::~CEncodedContent()
{
    delete _dictionary;
    delete _encodedText;
}
