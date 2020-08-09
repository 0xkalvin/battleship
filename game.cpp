#include "game.h"

Game::Game()
{
    this->is_game_over = this->player_to_move = 0;
    this->menu = new Menu();

    this->init_menu();
    this->mode = this->menu->get_chosen_mode();

    this->board = (Board **)malloc(this->mode * sizeof(Board *));
    this->score = (int *)malloc(this->mode * sizeof(int));

    for (int i = 0; i < this->mode; i++)
    {
        this->board[i] = new Board(this->board_size);
        this->score[i] = 0;
    }
}

Game::~Game()
{
    delete this->board;
    delete this->menu;
    delete this->score;
}

/* Handles the game logic, such as altering the board state based on the user input */
void Game::core(Coordinate *shot)
{
    try
    {

        if (this->board[this->player_to_move]->grid[shot->x][shot->y]->state != 0)
        {
            throw "INPUT::Coordinate was already revealed";
        }

        Coordinate *target_coordinate = this->board[this->player_to_move]->search_ship_in_coordinate(shot->x, shot->y);

        if (this->board[this->player_to_move]->grid[shot->x][shot->y]->state == 0 && target_coordinate)
        {
            this->board[this->player_to_move]->grid[shot->x][shot->y]->state = target_coordinate->state;

            this->score[this->player_to_move] += 10 * target_coordinate->state;

            this->board[this->player_to_move]->active_ships_coordinates -= 1;

            if (this->board[this->player_to_move]->active_ships_coordinates == 0)
            {
                this->is_game_over = 1;
            }
        }
        else
        {
            this->board[this->player_to_move]->grid[shot->x][shot->y]->state = EMPTY;
        }

        if (this->mode == 2)
        {

            this->player_to_move = !this->player_to_move;
        }
    }
    catch (const char *const error)

    {
        std::cout << "ERROR::" << error << std::endl;
    }
}

/*  Renders game interface based on its mode and current state  */
void Game::render()
{
    system("clear");

    std::cout << title;

    if (this->mode == 2)
    {
        printf("\t     PLAYER 1\t\t\t\t    PLAYER 2\n\n    ");

        for (int i = 0; i < this->board_size; i++)
        {
            printf("%2d ", i + 1);
        }

        printf("\t\t   ");

        for (int i = 0; i < this->board_size; i++)
        {
            printf("%2d ", i + 1);
        }

        printf("\n");

        for (int i = 0; i < this->board_size; i++)
        {

            printf(" %2c", 'a' + i);

            for (int j = 0; j < this->board_size; j++)
            {

                if (this->board[0]->grid[i][j]->state == -1)
                {
                    printf(" %2c", '.');
                }
                else if (this->board[0]->grid[i][j]->state == 0)
                {
                    printf(" %2c", '~');
                }
                else if (this->board[0]->grid[i][j]->state == 1)
                {
                    printf(" %2c", 'S');
                }
                else if (this->board[0]->grid[i][j]->state == 2)
                {
                    printf(" %2c", 'U');
                }
                else if (this->board[0]->grid[i][j]->state == 3)
                {
                    printf(" %2c", 'A');
                }
            }

            printf("\t\t%2c", 'a' + i);

            for (int j = 0; j < this->board_size; j++)
            {

                if (this->board[1]->grid[i][j]->state == -1)
                {
                    printf(" %2c", '.');
                }
                else if (this->board[1]->grid[i][j]->state == 0)
                {
                    printf(" %2c", '~');
                }
                else if (this->board[1]->grid[i][j]->state == 1)
                {
                    printf(" %2c", 'S');
                }
                else if (this->board[1]->grid[i][j]->state == 2)
                {
                    printf(" %2c", 'U');
                }
                else if (this->board[1]->grid[i][j]->state == 3)
                {
                    printf(" %2c", 'A');
                }
            }

            printf("\n");
        }

        printf("\t     Score %d\t\t\t\t    Score %d\n\n", this->score[0], this->score[1]);
    }
    else
    {

        printf("\t     PLAYER 1\n\n    ");
        for (int i = 0; i < this->board_size; i++)
        {
            printf("%2d ", i + 1);
        }

        printf("\n");

        for (int i = 0; i < this->board_size; i++)
        {

            printf(" %2c", 'a' + i);

            for (int j = 0; j < this->board_size; j++)
            {

                if (this->board[0]->grid[i][j]->state == -1)
                {
                    printf(" %2c", '.');
                }
                else if (this->board[0]->grid[i][j]->state == 0)
                {
                    printf(" %2c", '~');
                }
                else if (this->board[0]->grid[i][j]->state == 1)
                {
                    printf(" %2c", 'S');
                }
                else if (this->board[0]->grid[i][j]->state == 2)
                {
                    printf(" %2c", 'U');
                }
                else if (this->board[0]->grid[i][j]->state == 3)
                {
                    printf(" %2c", 'A');
                }
            }

            printf("\n");
        }

        printf("\t     Score %d\n\n", this->score[0]);
    }
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
            if (this->mode == 2)
            {
                std::cout << "Player " << this->player_to_move + 1 << " to move " << std::endl;
            }
            std::cout << "Enter a coordinate (e.g. e2 )" << '\n';

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

/*  Shows initial menu and set the game mode */
void Game::init_menu()
{
    system("clear");

    std::cout << title << '\n';

    this->menu->render();
}