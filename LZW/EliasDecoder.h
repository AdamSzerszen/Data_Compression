#pragma once
#include <string>
#include "BinaryConverter.h"

using std::string;

class CEliasDecoder
{
private:
    CEliasDecoder();
public:
    static int Decode(string* eliasCode);
    ~CEliasDecoder();
};

