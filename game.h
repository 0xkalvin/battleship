#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <map>

#include "board.h"
#include "menu.h"

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
    Menu* menu;
    Board** board;
    int is_game_over;
    int mode;
    int *score;
    int player_to_move;

public:
    Game();
    ~Game();
    void core(Coordinate* shot_coordinates);
    void render();
    Coordinate *read_shots_coordinates();
    int is_over();
    void init_menu();
    void render_winning_screen();

};

#endif