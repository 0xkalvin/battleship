#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class Coordinate
{

public:
    int x, y, state;
    Coordinate(int x, int y);
    ~Coordinate();
};

#endif