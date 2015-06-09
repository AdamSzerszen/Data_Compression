#include "Buffor.h"


CBuffor::CBuffor(int size) :
_size(size)
{
}

void CBuffor::PushBack(char element)
{
    string tempElement(1, element);
    if (_content.length() == _size)
    {
        _content.erase(0, 1);
        _content.append(tempElement);
    }
    else
    {
        _content.append(tempElement);
    }
}

void CBuffor::InitializeEncodingBuffor(string content)
{
    _content = content.substr(0, _size);
}

void CBuffor::InitializeDictionaryBuffor(char letter)
{
    string element(1, letter);
    for (int i = 0; i < _size; i++)
    {
        _content.append(element);
    }
}

string CBuffor::GetContent(int size)const
{
    return _content.substr(0, size);
}

CCoordinates* CBuffor::GetSubstringCoordinates(string maximalSubstring)
{
    int length = maximalSubstring.length();
    string substring = maximalSubstring;
    CCoordinates* coordinates;
    int distance = length;
    int x = 0;
    int y = 0;
    bool found = false;
    while (!found)
    {
        for (int i = _size - length; i >= 0; i--)
        {
            if (_content.substr(i, length) == substring)
            {
                x = _size - i;
                y = substring.length();
                found = true;
                coordinates = new CCoordinates(x, y);
                break;
            }
        }
        if (length == 0 && !found)
        {
            coordinates = new CCoordinates(0, maximalSubstring[0]);
            break;
        }
        if (!found)
        {
            substring.erase(substring.length() - 1, 1);
            length--;
        }
    }
    return coordinates;
}

CBuffor::~CBuffor()
{
}
