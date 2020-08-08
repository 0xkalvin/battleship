#ifndef COORDINATE_H
#define COORDINATE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

enum State
{
    EMPTY = -1,
    UNKNOWN = 0,
    SUBMARINE = 1,
    CRUISER = 2,
    CARRIER = 3
};

class Coordinate
{

private:
    int x, y;
    State state;
    friend class Game;
    friend class Board;

public:
    Coordinate(int x, int y);
    Coordinate(int x, int y, State state);
    ~Coordinate();
    int operator==(Coordinate *c);
    friend std::ostream& operator<<(std::ostream& out, const Coordinate& dt);
};

#endif