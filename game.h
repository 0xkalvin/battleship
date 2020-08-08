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
    const int number_of_carriers = 1;
    const int number_of_cruisers = 2;
    const int number_of_submarines = 5;

private:
    Menu *menu;
    Board* board;
    int is_game_over;
    int mode;
    int score;
    int active_ships_coordinates;
    std::map<std::string, Coordinate*> ships;

public:
    Game();
    ~Game();
    void core(Coordinate* shot_coordinates);
    void render();
    Coordinate *read_shots_coordinates();
    int is_over();
    int get_score();
    void show_menu();

    Coordinate* search_ship_in_coordinate(int x, int y);
    void setup_ships();
    void setup_ship(int size, int n, State target_state);

};

#endif