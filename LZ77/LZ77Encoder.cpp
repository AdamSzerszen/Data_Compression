#include "LZ77Encoder.h"


CLZ77Encoder::CLZ77Encoder()
{
}

string CLZ77Encoder::encodeLetterFromOutsideBuffor(char letter)
{
    return "00000000" + CBinaryConverter::CharToBinaryString(letter);
}

string CLZ77Encoder::encodeLetterFromBuffer(int distance, int length)
{
    string distanceAsString = CBinaryConverter::DecToBin(distance);
    string lengthAsString = CBinaryConverter::DecToBin(length);
    if (distanceAsString.length() < 8)
    {
        int difference = 8 - distanceAsString.length();
        for (int i = 0; i < difference; i++)
        {
            distanceAsString = "0" + distanceAsString;
        }
    }
    if (lengthAsString.length() < 8)
    {
        int difference = 8 - lengthAsString.length();
        for (int i = 0; i < difference; i++)
        {
            lengthAsString = "0" + lengthAsString;
        }
    }
    return distanceAsString + lengthAsString;
}

string CLZ77Encoder::Encode(string textToEncode)
{
    int counter = 0;
    string tempWord = "";
    auto dictionaryBuffor = new CBuffor(255);
    auto encodingBuffor = new CBuffor(256);
    unsigned size = textToEncode.length();
    
    dictionaryBuffor->InitializeDictionaryBuffor(textToEncode[0]);
    encodingBuffor->InitializeEncodingBuffor(textToEncode);
    // kodowanie ma dzia³aæ tak jak na stronie msdn(patrz zak³adki);
    // w pêtli sprawdzamy czy w buforze s³ownika nie ma maksymalnego podci¹gu, jeœli tak, to wpisujemy wskaŸnik na niego (i, j)
    // a jak nie, zmniejszamy o ostatni znak nasz podci¹g i znowu sprawdzamy w buforze s³ownika i tak do koñca

    delete dictionaryBuffor;
    delete encodingBuffor;
}

CLZ77Encoder::~CLZ77Encoder()
{
}
