#include "Encoder.h"


CEncoder::CEncoder()
{
}


string CEncoder::setLastParityBit(string block)
{
    string tempBlock = block;
    int counter = 0;
    for (int i = 0; i < 7; i++)
    {
        if (block[i] == '1')
        {
            counter++;
        }
    }
    if (counter % 2 != 0)
    {
        tempBlock[7] = '1';
    }

    return tempBlock;
}

string CEncoder::setDataBits(string block)
{
    string tempBlock = "00000000";

    tempBlock[2] = block[0];
    tempBlock[4] = block[1];
    tempBlock[5] = block[2];
    tempBlock[6] = block[3];

    return tempBlock;
}

string CEncoder::prepareHalfParity(string block)
{
    if (block.length() < 4)
    {
        for (int i = 0; i < 4 - block.length(); i++)
        {
            block = "0" + block;
        }
    }
    string tempBlock = setDataBits(block);
    int tempBit = std::stoi(block.substr(0, 1));
    tempBit = tempBit ^ std::stoi(block.substr(1, 1));
    tempBit = tempBit ^ std::stoi(block.substr(3, 1));
    if (tempBit == 1)
    {
        tempBlock[0] = '1';
    }

    tempBit = std::stoi(block.substr(0, 1));
    tempBit = tempBit ^ std::stoi(block.substr(2, 1));
    tempBit = tempBit ^ std::stoi(block.substr(3, 1));
    if (tempBit == 1)
    {
        tempBlock[1] = '1';
    }

    tempBit = std::stoi(block.substr(1, 1));
    tempBit = tempBit ^ std::stoi(block.substr(2, 1));
    tempBit = tempBit ^ std::stoi(block.substr(3, 1));
    if (tempBit == 1)
    {
        tempBlock[3] = '1';
    }

    tempBlock = setLastParityBit(tempBlock);

    return tempBlock;
}

string CEncoder::prepareParityBits(string block)
{
    string firstTetrade = block.substr(0, 4);
    string secondTetrade = block.substr(4, 4);
    string firstEncodedBlock = prepareHalfParity(firstTetrade);
    string secondEncodedBlock = prepareHalfParity(secondTetrade);
    return firstEncodedBlock + secondEncodedBlock;
}

string CEncoder::encodeSingleCharacter(string symbol)
{
    string hammingCode = prepareParityBits(symbol);
    return hammingCode;
}

string CEncoder::EncodeHamming(string textToEncode)
{
    auto encoder = new CEncoder();
    string encodedText = "";
    string tempText = textToEncode;
    string tempBlock = "";
    string encodedSingleBlock = "";

    while (tempText.length() >= 8)
    {
        tempBlock = tempText.substr(0, 8);
        tempText.erase(0, 8);
        encodedSingleBlock = encoder->encodeSingleCharacter(tempBlock);
        encodedText.append(encodedSingleBlock);
    }

    delete encoder;
    return encodedText;
}

CEncoder::~CEncoder()
{
}
