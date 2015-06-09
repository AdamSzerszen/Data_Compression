#pragma once
#include <string>
#include <vector>
#include <bitset>

using std::bitset;
using std::vector;
using std::string;

class CBinaryConverter
{
private:
    CBinaryConverter();
public:
    static int BinToDec(string binary);
    static string DecToBin(int decimal);
    static string CharToBinaryString(char symbol);
    static void GetASCIS(string rawString, vector<char>* ascis);
    ~CBinaryConverter();
};

