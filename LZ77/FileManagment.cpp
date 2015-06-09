#include "FileManagment.h"


CFileManagment::CFileManagment()
{
}

string CFileManagment::LoadFile(const string input)
{
    std::ifstream is(input, std::ifstream::binary);

    // Find the length of the file
    is.seekg(0, is.end);
    std::streampos length = is.tellg();
    is.seekg(0, is.beg);

    // Create a vector to read it into
    vector<unsigned char> bytes(length);

    // Actually read data
    is.read((char *)&bytes[0], length);

    // Close the file explicitly, since we're finished with it
    is.close();
    string str(bytes.begin(), bytes.end());
    return str;
}


void CFileManagment::SaveFile(const string output, string dataToSave)
{
    std::ofstream encodedFile;
    encodedFile.open(output);
    encodedFile << dataToSave;
    encodedFile.close();
}

CFileManagment::~CFileManagment()
{
}
