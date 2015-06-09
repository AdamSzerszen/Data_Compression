#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class CDecoder
{
private:
    int _numberOfErrors;

    CDecoder();
    string decodeSingleCharacter(string block);
    void repairData(string block);
    string getInformationBits(string block);
    static int checkParity(string block);
public:
    static string Decode(string textToEncode);
    ~CDecoder();
};

