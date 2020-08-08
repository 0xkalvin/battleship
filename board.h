#ifndef BOARD_H
#define BOARD_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

#include "coordinate.h"

class Board
{
    const int number_of_carriers = 1;
    const int number_of_cruisers = 2;
    const int number_of_submarines = 5;

private:
    int active_ships_coordinates;
    int size;
    Coordinate ***grid;
    std::map<std::string, Coordinate *> ships;
    friend class Game;

public:
    Board(int size);
    ~Board();
    Coordinate *search_ship_in_coordinate(int x, int y);
    void setup_ship(int size, int n, State target_state);
    int count_active_ships_coordinates();
};

#endif