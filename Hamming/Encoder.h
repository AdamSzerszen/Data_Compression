#pragma once
#include <string>

using std::string;

class CEncoder
{
private:
    string encodeSingleCharacter(string symbol);
    string prepareParityBits(string block);
    string prepareHalfParity(string block);
    string setDataBits(string block);
    string setLastParityBit(string block);
    CEncoder();
public:
    static string EncodeHamming(string textToEncode);
    ~CEncoder();
};

