#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include "coordinate.h"

class Board
{

private:
    int size;
    Coordinate ***state;

public:
    Board(int size);
    ~Board();
};

#endif