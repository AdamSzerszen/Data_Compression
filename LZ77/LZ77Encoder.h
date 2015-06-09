#pragma once
#include <string>
#include "BinaryConverter.h"
#include "Buffor.h"

using std::string;

class CLZ77Encoder
{
private:
    CLZ77Encoder();
    string encodeLetterFromOutsideBuffor(char letter);
    string encodeLetterFromBuffer(int distance, int length);
public:
    static string Encode(string textToEncode);
    ~CLZ77Encoder();
};

