#include "LZ77.h"


CLZ77::CLZ77()
{
}

void CLZ77::Encode(const string input, const string output)
{
    string loadedText = CFileManagment::LoadFile(input);
    string encodedText = CLZ77Encoder::Encode(loadedText);
    CFileManagment::SaveFile(output, encodedText);
}

void CLZ77::Decode(const string input, const string output)
{
    string loadedText = CFileManagment::LoadFile(input);
    string decodedText = "";

    CFileManagment::SaveFile(output, decodedText);
}

CLZ77::~CLZ77()
{
}
