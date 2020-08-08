#ifndef MENU_H
#define MENU_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

class Menu
{

private:
    int chosen_mode;
    friend class Game;

public:
    Menu();
    ~Menu();
    void render();
    int get_chosen_mode();
};

#endif