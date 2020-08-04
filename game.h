#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

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

private:
    int **board;
    int is_game_over;
    int **carriers;
    int **cruisers;
    int *submarines;

public:
    Game();
    ~Game();
    void core(Coordinate* shot_coordinates);
    void draw();
    Coordinate *input();
    int is_over();
    int did_it_hit(int x, int y);

};

#endif