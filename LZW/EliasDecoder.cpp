#include "EliasDecoder.h"


CEliasDecoder::CEliasDecoder()
{
}

int CEliasDecoder::Decode(string* eliasCode)
{
    int counter = 0;
    int decodedNumber = 0;
    int nBitsDecimalRepresentation = 0;
    string nBitsBinaryRepresentation = "";
    string decodedNumberBinaryRepresentation = "";

    while ((*(eliasCode))[counter] != '1')
    {
        counter++;
    }
    (*eliasCode).erase(0, counter);
    nBitsBinaryRepresentation = (*eliasCode).substr(0, counter + 1);
    (*eliasCode).erase(0, counter + 1);
    nBitsDecimalRepresentation = CBinaryConverter::BinToDec(nBitsBinaryRepresentation);
    decodedNumberBinaryRepresentation = "1" + (*eliasCode).substr(0, nBitsDecimalRepresentation - 1);
    decodedNumber = CBinaryConverter::BinToDec(decodedNumberBinaryRepresentation);
    (*eliasCode).erase(0, nBitsDecimalRepresentation - 1);

    return decodedNumber;
}

CEliasDecoder::~CEliasDecoder()
{
}
