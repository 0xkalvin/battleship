#include "game.h"

int main(void)
{

    Game *game = new Game();

    while (!game->is_over())
    {
        game->render();

        Coordinate *shot_coordinates = game->read_shots_coordinates();

        game->core(shot_coordinates);
    }

    return 0;
}