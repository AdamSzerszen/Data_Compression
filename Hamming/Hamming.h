#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <bitset>
#include "Encoder.h"
#include "Decoder.h"
#include "Noiser.h"
#include "BlockComparer.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::bitset;

class CHamming
{
private:
    CHamming();
    string loadFile(const string fileName);
    static void saveFile(const string fileName, vector<char>* fileToSave);
    string CHamming::decToBin(int number);
    static void getASCIS(string rawString, vector<char>* ascis);
    string charToBinaryString(char symbol);
    string loadFullFile(string textToNoise);
    static string getBinaryFile(const string input);
    static void savePreparedFile(const string output, string fileToSave);
public:
    static void Encode(const string input, const string output);
    static void Decode(const string input, const string output);
    static void MakeSomeNoise(const string input, const string output, int probabilityOfNoise);
    static void Compare(const string inputOne, const string inputTwo);
    ~CHamming();
};

