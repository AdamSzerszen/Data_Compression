#pragma once
#include <string>

using std::string;

class CBlockComparer
{
private:
    CBlockComparer();
public:
    static int Compare(string fileOne, string fileTwo);
    ~CBlockComparer();
};

