#pragma once
class CCoordinates
{
private:
    int _x;
    int _y;
public:
    CCoordinates(int x, int y);
    int X(void)const;
    int Y(void)const;
    ~CCoordinates();
};

