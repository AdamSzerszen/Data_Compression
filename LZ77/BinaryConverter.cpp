#include "BinaryConverter.h"


CBinaryConverter::CBinaryConverter()
{
}

int CBinaryConverter::BinToDec(string binary)
{
    int result = 0;
    int pow = 1;
    for (int i = binary.length() - 1; i >= 0; --i, pow <<= 1)
        result += (binary[i] - '0') * pow;

    return result;
}

string CBinaryConverter::DecToBin(int decimal)
{
    if (decimal == 0) return "0";
    if (decimal == 1) return "1";

    if (decimal % 2 == 0)
        return DecToBin(decimal / 2) + "0";
    else
        return DecToBin(decimal / 2) + "1";
}

string CBinaryConverter::CharToBinaryString(char symbol)
{
    string solution = "";
    int symbolValue = symbol;
    unsigned char value;
    if (symbolValue < 0)
    {
        value = symbolValue;
        solution = DecToBin((int)value);
    }
    else
    {
        solution = DecToBin(symbolValue);
    }
    int size = solution.length();
    if (size < 8)
    {
        for (int i = 0; i < 8 - size; i++)
        {
            solution = "0" + solution;
        }
    }
    return solution;
}

void CBinaryConverter::GetASCIS(string rawString, vector<char>* ascis)
{
    string tempString = rawString;
    string rawAsci;
    unsigned char betterAsci;
    char myAsci;
    int myAsciValue;

    while (tempString.length() >= 8)
    {
        rawAsci = tempString.substr(0, 8);
        bitset<8> b(rawAsci);
        myAsciValue = b.to_ulong();
        if (myAsciValue < 0)
        {
            betterAsci = myAsciValue;
            ascis->push_back(betterAsci);
        }
        else
        {
            myAsci = myAsciValue;
            ascis->push_back(myAsci);
        }
        tempString.erase(0, 8);
    }
}

CBinaryConverter::~CBinaryConverter()
{
}
