#include "Decoder.h"


CDecoder::CDecoder() :
_numberOfErrors(0)
{
}

string CDecoder::getInformationBits(string block)
{
    string tempInformationBints = "";
    tempInformationBints.append(block.substr(2,1));
    tempInformationBints.append(block.substr(4, 1));
    tempInformationBints.append(block.substr(5, 1));
    tempInformationBints.append(block.substr(6, 1));
    return tempInformationBints;
}

int CDecoder::checkParity(string block)
{
    int counter = 0;
    for (int i = 0; i < block.length(); i++)
    {
        if (block[i] == '1')
        {
            counter++;
        }
    }
    return counter;
}

void CDecoder::repairData(string block)
{
    string parityOne = "";
    string parityTwo = "";
    string parityFour = "";
    string parityEight = "";
    
    int numberOfErrors = 0;
    int errorPosition = 0;
    int lastBit = 0;

    parityOne += block.substr(0, 1);
    parityOne += block.substr(2, 1);
    parityOne += block.substr(4, 1);
    parityOne += block.substr(6, 1);

    parityTwo += block.substr(1, 2);
    parityTwo += block.substr(5, 2);

    parityFour += block.substr(3, 4);

    parityEight += block.substr(7, 1);

    errorPosition += checkParity(parityOne);
    errorPosition += checkParity(parityTwo);
    errorPosition += checkParity(parityFour);

    if (errorPosition > 0)
    {
        numberOfErrors++;
        if (block[errorPosition - 1] == '1')
        {
            block[errorPosition - 1] = '0';
        }
        else
        {
            block[errorPosition - 1] = '1';
        }
    }

    lastBit = checkParity(block) % 2;
    if ((parityEight[0] == '0' && lastBit != 0)
        || (parityEight[0] == '1' && lastBit != 1))
    {
        numberOfErrors++;
    }

    if (numberOfErrors > 1)
    {
        _numberOfErrors++;
    }
}

string CDecoder::decodeSingleCharacter(string block)
{
    string tempDecodedCharacter = "";
    string firstBlock = block.substr(0, 8);
    string secondBlock = block.substr(8, 8);
    repairData(firstBlock);
    repairData(secondBlock);
    tempDecodedCharacter = getInformationBits(firstBlock) + getInformationBits(secondBlock);
    return tempDecodedCharacter;
}

string CDecoder::Decode(string textToDecode)
{
    auto decoder = new CDecoder();
    string decodedText = "";
    string tempBlock = "";
    string tempDecodedBlock = "";
    string tempTextToDecode = textToDecode;

    while (tempTextToDecode.length() > 0)
    {
        tempBlock = tempTextToDecode.substr(0, 16);
        tempDecodedBlock = decoder->decodeSingleCharacter(tempBlock);
        decodedText.append(tempDecodedBlock);
        tempTextToDecode.erase(0, 16);
    }
    cout << "Number of double errors: " << decoder->_numberOfErrors << endl;
    delete decoder;
    return decodedText;
}

CDecoder::~CDecoder()
{
}
