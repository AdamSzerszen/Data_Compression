#include "Hamming.h"


CHamming::CHamming()
{
}

string CHamming::loadFile(const string fileName)
{
    std::ifstream is(fileName, std::ifstream::binary);

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

void CHamming::saveFile(const string fileName, vector<char>* fileToSave)
{
    std::ofstream encodedFile;
    encodedFile.open(fileName);
    unsigned size = fileToSave->size();
    for (unsigned i = 0; i < size; i++)
    {
        encodedFile << fileToSave->at(i);
    }
    encodedFile.close();
    delete fileToSave;
}

string CHamming::charToBinaryString(char symbol)
{
    string solution = "";
    int symbolValue = symbol;
    unsigned char value;
    if (symbolValue < 0)
    {
        value = symbolValue;
        solution = decToBin((int)value);
    }
    else
    {
        solution = decToBin(symbolValue);
    }
    int size = solution.length();
    if (size < 8)
    {
        for (int i = 0; i < 8 - size; i++)
        {
            solution = "0" + solution;
        }
    }
    return solution;
}

string CHamming::decToBin(int number)
{
    if (number == 0) return "0";
    if (number == 1) return "1";

    if (number % 2 == 0)
        return decToBin(number / 2) + "0";
    else
        return decToBin(number / 2) + "1";
}

string CHamming::loadFullFile(string fileToLoad)
{
    string textAsBinary = "";
    string tempBlock = "";
    for (unsigned i = 0; i < fileToLoad.length(); i++)
    {
        tempBlock = charToBinaryString(fileToLoad.at(i));
        textAsBinary.append(tempBlock);
    }
    return textAsBinary;
}

string CHamming::getBinaryFile(const string input)
{
    auto hamming = new CHamming();
    auto fileAsString = hamming->loadFile(input);
    auto fileBinaryAsString = hamming->loadFullFile(fileAsString);
    delete hamming;
    return fileBinaryAsString;
}

void CHamming::savePreparedFile(const string output, string fileToSave)
{
    auto myASCIs = new vector<char>();
    getASCIS(fileToSave, myASCIs);
    saveFile(output, myASCIs);
}

void CHamming::getASCIS(string rawString, vector<char>* ascis)
{
    string tempString = rawString;
    string rawAsci;
    unsigned char betterAsci;
    char myAsci;
    int myAsciValue;

    while (tempString.length() >= 8)
    {
        rawAsci = tempString.substr(0, 8);
        bitset<8> b(rawAsci);
        myAsciValue = b.to_ulong();
        if (myAsciValue < 0)
        {
            betterAsci = myAsciValue;
            ascis->push_back(betterAsci);
        }
        else
        {
            myAsci = myAsciValue;
            ascis->push_back(myAsci);
        }
        tempString.erase(0, 8);
    }
}

void CHamming::Encode(const string input, const string output)
{
    auto binaryFile = getBinaryFile(input);
    auto encodedString = CEncoder::EncodeHamming(binaryFile);
    savePreparedFile(output, encodedString);
}

void CHamming::Decode(const string input, const string output)
{
    auto binaryFile = getBinaryFile(input);
    auto decodedString = CDecoder::Decode(binaryFile);
    savePreparedFile(output, decodedString);
}

void CHamming::MakeSomeNoise(const string input, const string output, int probabilityOfNoise)
{
    auto binaryFile = getBinaryFile(input);
    auto noisedString = CNoiser::CreateNoise(binaryFile, probabilityOfNoise);
    savePreparedFile(output, noisedString);
}



void CHamming::Compare(const string inputOne, const string inputTwo)
{
    auto fileOneBinary = getBinaryFile(inputOne);
    auto fileTwoBinary = getBinaryFile(inputTwo);

    int result = CBlockComparer::Compare(fileOneBinary, fileTwoBinary);
    cout << "Number of errors: ";
    cout << result << endl;
}

CHamming::~CHamming()
{
}
