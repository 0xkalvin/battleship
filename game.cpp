#include "game.h"

Game::Game()
{
    this->is_game_over = this->score = 0;
    this->menu = new Menu();
    this->board = new Board(this->board_size);

    this->setup_ship(5, 1, CARRIER);
    this->setup_ship(3, 2, CRUISER);
    this->setup_ship(1, 5, SUBMARINE);

    this->active_ships_coordinates = this->number_of_carriers * 5 +
                                     this->number_of_cruisers * 3 + this->number_of_submarines;

    this->show_menu();

    for (const auto &p : this->ships)
    {
        std::cout << *p.second << std::endl;
    }
}

Game::~Game()
{
    delete this->board;
}

/* Handles the game logic, such as altering the board state based on the user input */
void Game::core(Coordinate *shot)
{
    try
    {

        if (this->board->grid[shot->x][shot->y]->state != 0)
        {
            throw "INPUT::Coordinate was already revealed";
        }

        Coordinate *target_coordinate = this->search_ship_in_coordinate(shot->x, shot->y);

        if (this->board->grid[shot->x][shot->y]->state == 0 && target_coordinate)
        {
            this->board->grid[shot->x][shot->y]->state = target_coordinate->state;
            this->score += 10 * target_coordinate->state;
            this->active_ships_coordinates -= 1;

            if (this->active_ships_coordinates == 0)
            {
                this->is_game_over = 1;
            }
        }
        else
        {
            this->board->grid[shot->x][shot->y]->state = EMPTY;
        }
    }
    catch (const char *const error)

    {
        std::cout << "ERROR::" << error << std::endl;
    }
}

/*  Renders game interface based on its current state */
void Game::render()
{
    system("clear");

    std::cout << title << '\n';

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

            if (this->board->grid[i][j]->state == -1)
            {
                printf(" %2c", '.');
            }
            else if (this->board->grid[i][j]->state == 0)
            {
                printf(" %2c", '~');
            }
            else if (this->board->grid[i][j]->state == 1)
            {
                printf(" %2c", 'S');
            }
            else if (this->board->grid[i][j]->state == 2)
            {
                printf(" %2c", 'U');
            }
            else if (this->board->grid[i][j]->state == 3)
            {
                printf(" %2c", 'A');
            }
        }
        printf("\n");
    }

    printf("Score %d \n", this->score);
}

int Game::get_score()
{
    return this->score;
}

/* Returns game state */
int Game::is_over()
{
    return this->is_game_over;
}

/*  Handles player input to get shot coordinates */
Coordinate *Game::read_shots_coordinates()
{

    int is_valid_input = 0;

    while (!is_valid_input)
    {
        try
        {
            std::cout << "Shot a coordinate (e.g.: e2 )" << '\n';

            std::string shot_input;
            getline(std::cin, shot_input);

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
            std::cout << "ERROR::" << error << std::endl;
        }
    }
}

/*  Checks if a passed coordinate matches any ship position. If so, returns ship coordinate */
Coordinate *Game::search_ship_in_coordinate(int x, int y)
{
    std::string key = std::to_string(x) + std::to_string(y);

    Coordinate *exists = this->ships[key];

    if (exists)
    {
        return exists;
    }

    return NULL;
}

/*  Initialize a type of ship, setting up its coordinates by size and quantity */
void Game::setup_ship(int size, int n, State target_state)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int is_coordinates_valid = 1;

        do
        {

            int x = rand() % this->board_size;
            int y = rand() % this->board_size;
            int j = 1;

            while (j < size + 1)
            {

                Coordinate *c = new Coordinate(x + j, y);
                std::string key = std::to_string(x + j) + std::to_string(y);

                if (this->ships.count(key) || c->x >= 9 || c->y >= 9)
                {
                    is_coordinates_valid = 0;
                }
                else
                {
                    is_coordinates_valid = 1;
                }

                j++;
            }

            if (is_coordinates_valid)
            {
                j = 1;

                while (j < size + 1)
                {

                    Coordinate *c = new Coordinate(x + j, y, target_state);
                    std::string key = std::to_string(x + j) + std::to_string(y);

                    this->ships[key] = c;
                    j++;
                }
            }

        } while (!is_coordinates_valid);
    }
}

/*  Shows initial menu and set the game mode */
void Game::show_menu()
{
    system("clear");

    std::cout << title << '\n';

    this->menu->render();

    this->mode = this->menu->get_chosen_mode();

}