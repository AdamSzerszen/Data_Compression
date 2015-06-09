#include "EliasEncoder.h"


CEliasEncoder::CEliasEncoder()
{
}

string CEliasEncoder::Encode(int number)
{
    string eliasCode = "";
    string numberBinaryCode = CBinaryConverter::DecToBin(number);
    string nBitsBinaryRepresentation = CBinaryConverter::DecToBin(numberBinaryCode.length());
    int kBits = nBitsBinaryRepresentation.length() - 1;

    for (int i = 0; i < kBits; i++)
    {
        eliasCode.append("0");
    }
    eliasCode.append(nBitsBinaryRepresentation);
    eliasCode.append(numberBinaryCode.substr(1, numberBinaryCode.length() - 1));

    return eliasCode;
}

CEliasEncoder::~CEliasEncoder()
{
}
