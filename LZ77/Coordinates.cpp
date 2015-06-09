#include "Coordinates.h"


CCoordinates::CCoordinates(int x, int y):
_x(x),
_y(y)
{
}

int CCoordinates::X(void)const
{
    return _x;
}

int CCoordinates::Y(void)const
{
    return _y;
}

CCoordinates::~CCoordinates()
{
}
