#include "BlockComparer.h"


CBlockComparer::CBlockComparer()
{
}

int CBlockComparer::Compare(string fileOne, string fileTwo)
{
    int numberOfErrors = 0;
    string textOne = fileOne;
    string textTwo = fileTwo;
    string blockOne = "";
    string blockTwo = "";

    while (textOne.length() > 0 && textTwo.length() > 0)
    {
        blockOne = textOne.substr(0, 4);
        blockTwo = textTwo.substr(0, 4);

        if (blockOne.compare(blockTwo) != 0)
        {
            numberOfErrors++;
        }

        textOne.erase(0, 4);
        textTwo.erase(0, 4);
    }

    return numberOfErrors;
}

CBlockComparer::~CBlockComparer()
{
}
