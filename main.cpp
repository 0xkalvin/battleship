#include "game.h"

int main(void)
{

    Game *game = new Game();

    while (!game->is_over())
    {
        game->draw();

        Coordinate *shot_coordinates = game->input();

        game->core(shot_coordinates);
    }

    return 0;
}