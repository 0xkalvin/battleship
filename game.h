#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

#include "coordinate.h"

class Game
{
    const char *title = R"(

    ██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗ 
    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗
    ██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝
    ██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝ 
    ██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║     
    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝     
                                                                                
    )";

    const int board_size = 9;
    const int number_of_carriers = 1;
    const int number_of_cruisers = 2;
    const int number_of_submarines = 5;

private:
    int **board;
    int is_game_over;
    int **carriers;
    int **cruisers;
    int **submarines;

public:
    Game();
    ~Game();
    void core(Coordinate* shot_coordinates);
    void draw();
    Coordinate *input();
    int is_over();
    
    int did_it_hit(int x, int y);
    void setup_ships();

};

#endif