#include <iostream>
#include <conio.h>
#include "LZW.h"
#include "EliasEncoder.h"
#include "EliasDecoder.h"

using std::cout;
using std::endl;

int main(void)
{
    CLZW::Encode("plainText.txt", "encodedText.txt", "dictionary.dat");
    CLZW::Decode("encodedText.txt", "plainText2.txt", "dictionary.dat");

    /*int numberD;
    string encoded;
    for (int i = 2; i < 33; i++)
    {
        encoded = CEliasEncoder::Encode(i);
        cout << "Encoded: " << i;
        cout << " = " << encoded;
        cout << " Decoded = " << CEliasDecoder::Decode(&encoded);
        cout << endl;
    }*/

    system("pause");
    return 0;
}