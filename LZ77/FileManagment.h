#pragma once
#include <string>
#include <fstream>
#include <vector>

using std::string;
using std::vector;

class CFileManagment
{
private:
    CFileManagment();
public:
    static string LoadFile(const string input);
    static void SaveFile(const string output, string dataToSave);
    ~CFileManagment();
};

