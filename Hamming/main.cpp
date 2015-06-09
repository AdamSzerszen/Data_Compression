#include <iostream>
#include <string>
#include "Hamming.h"

int main(void)
{
    CHamming::Encode("plainText.txt", "encodedText.txt");
    CHamming::MakeSomeNoise("encodedText.txt", "noisedText.txt", 40);
    CHamming::Decode("noisedText.txt", "plainText2.txt");
    CHamming::Compare("plainText2.txt", "plainText.txt");
    system("pause");
    return 0;
}