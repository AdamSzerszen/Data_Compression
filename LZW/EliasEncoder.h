#pragma once
#include <string>
#include "BinaryConverter.h"

using std::string;

class CEliasEncoder
{
private:
    CEliasEncoder();
public:
    static string Encode(int number);
    ~CEliasEncoder();
};

