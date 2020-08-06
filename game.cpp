#include "game.h"

using namespace std;

Game::Game()
{
    this->is_game_over = 0;
    this->board = new Board(this->board_size);
    this->setup_ships();
}

Game::~Game()
{
    delete this->board;
    delete this->carriers;
    delete this->cruisers;
    delete this->submarines;

}

void Game::core(Coordinate *shot)
{

    int was_hit = this->did_it_hit(shot->x, shot->y);

    if (this->board->grid[shot->x][shot->y]->state == 0 && was_hit)
    {
        this->board->grid[shot->x][shot->y]->state = 1;
    }
    else if (this->board->grid[shot->x][shot->y]->state == 1 && was_hit)
    {
        this->board->grid[shot->x][shot->y]->state = 1;
    }
    else
    {

        this->board->grid[shot->x][shot->y]->state = -1;
    }
}

void Game::draw()
{
    system("clear");

    cout << title << '\n';

    printf("   ");
    for (int i = 0; i < board_size; i++)
    {
        printf(" %2d", i + 1);
    }

    printf("\n");

    for (int i = 0; i < board_size; i++)
    {
        printf(" %2c", 'a' + i);
        for (int j = 0; j < board_size; j++)
        {
            if (this->board->grid[i][j]->state == 0)
            {
                printf("  ~");
            }
            else if (this->board->grid[i][j]->state== 1)
            {
                printf("  X");
            }
            else if (this->board->grid[i][j]->state== -1)
            {
                printf(" .");
            }
        }
        printf("\n");
    }
}

int Game::is_over()
{
    return this->is_game_over;
}

Coordinate *Game::input()
{

    int is_valid_input = 0;

    while (!is_valid_input)
    {
        try
        {
            cout << "Shot a coordinate (e.g.: e2 )" << '\n';

            string shot_input;
            getline(cin, shot_input);

            if (shot_input.length() != 2)
            {
                throw "INPUT::Shot coordinates must have two characters";
            }

            int x, y;

            x = (int)shot_input[0] - 97; // 97 is 'a' ASCII value
            y = (int)shot_input[1] - 49; // 49 is '1' ASCII value

            if (x < 0 || x > 9 || y < 0 || y > 9)
            {
                throw "INPUT::Shot coordinates are out of range";
            }

            return new Coordinate(x, y);
        }
        catch (const char *const error)
        {
            cout << "ERROR::" << error << endl;
        }
    }
}

int Game::did_it_hit(int x, int y)
{
    return 1;
}

void Game::setup_ships()
{

    srand(time(NULL));

    this->carriers = (int **)malloc(this->number_of_carriers * sizeof(int *));
    for (int i = 0; i < this->number_of_carriers; i++)
    {
        this->carriers[i] = (int *)malloc(2 * sizeof(int));

        for (int j = 0; j < 2; j++)
        {
            this->carriers[i][j] = rand() % 10;
        }
    }

    this->cruisers = (int **)malloc(this->number_of_cruisers * sizeof(int *));
    for (int i = 0; i < this->number_of_cruisers; i++)
    {
        this->cruisers[i] = (int *)malloc(2 * sizeof(int));

        for (int j = 0; j < 2; j++)
        {
            this->cruisers[i][j] = rand() % 10;
        }
    }

    this->submarines = (int **)malloc(this->number_of_submarines * sizeof(int *));
    for (int i = 0; i < this->number_of_submarines; i++)
    {
        this->submarines[i] = (int *)malloc(2 * sizeof(int));

        for (int j = 0; j < 2; j++)
        {
            this->submarines[i][j] = rand() % 10;
        }
    }
}