#pragma once
#include <string>
#include "Coordinates.h"

using std::string;

class CBuffor
{
private:
    int _size;
   string _content;
public:
    CBuffor(int size);
    void InitializeEncodingBuffor(string content);
    void InitializeDictionaryBuffor(char letter);
    void PushBack(char element);
    string GetContent(int size)const;
    CCoordinates* GetSubstringCoordinates(string maximalSubstring);
    ~CBuffor();
};

