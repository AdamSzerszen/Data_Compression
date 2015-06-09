#pragma once
#include <string>
#include "FileManagment.h"
#include "LZ77Encoder.h"

using std::string;

class CLZ77
{
private:
    CLZ77();
public:
    static void Encode(const string input, const string output);
    static void Decode(const string input, const string output);
    ~CLZ77();
};

