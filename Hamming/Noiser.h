#pragma once
#include <string>
#include <ctime>

using std::string;

class CNoiser
{
private:
    int _probabilityOfNoise;

    CNoiser(int probabilityOfNoise);
    void noiseSingleBit(char* symbol);
    void noiseFullText(string* textToNoise);
public:
    static string CreateNoise(string textToNoise, int probabilityOfNoise);
    ~CNoiser();
};

