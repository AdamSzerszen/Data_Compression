#include "Noiser.h"


CNoiser::CNoiser(int probabilityOfNoise):
_probabilityOfNoise(probabilityOfNoise)
{
}

void CNoiser::noiseSingleBit(char* symbol)
{
    srand(time(NULL));
    int percent = rand() % 100 + 1;
    if (percent > this->_probabilityOfNoise)
    {
        if (*symbol == '0')
        {
            *symbol = '1';
        }
        else
        {
            *symbol = '0';
        }
    }
}

void CNoiser::noiseFullText(string* textToNoise)
{
    int length = textToNoise->length();
    for (unsigned i = 0; i < length; i++)
    {
        noiseSingleBit(&(*textToNoise)[i]);
    }
}

string CNoiser::CreateNoise(string textToNoise, int probabilityOfNoise)
{
    auto noiser = new CNoiser(probabilityOfNoise);
    string tempText = textToNoise;
    noiser->noiseFullText(&tempText);
    delete noiser;
    return tempText;
}

CNoiser::~CNoiser()
{
}
