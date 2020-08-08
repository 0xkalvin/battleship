#include "board.h"

Board::Board(int size)
{
    this->size = size;
    this->grid = (Coordinate ***)malloc(this->size * sizeof(Coordinate **));

    for (int i = 0; i < this->size; i++)
    {
        this->grid[i] = (Coordinate **)malloc(this->size * sizeof(Coordinate *));

        for (int j = 0; j < this->size; j++)
        {
            this->grid[i][j] = (Coordinate *)malloc(this->size * sizeof(Coordinate));
            this->grid[i][j]->x = i;
            this->grid[i][j]->y = j;
            this->grid[i][j]->state = UNKNOWN;
        }
    }

    this->setup_ship(5, this->number_of_carriers, CARRIER);
    this->setup_ship(3, this->number_of_cruisers, CRUISER);
    this->setup_ship(1, this->number_of_submarines, SUBMARINE);

    this->active_ships_coordinates = this->number_of_carriers * 5 +
                                     this->number_of_cruisers * 3 + this->number_of_submarines;

    std::cout << "SHIPPS \n";
    for (const auto &p : this->ships)
    {
        std::cout << *p.second << std::endl;
    }
}

Board::~Board()
{
    delete this->grid;
}

/*  Initialize a type of ship, setting up its coordinates by size and quantity */
void Board::setup_ship(int size, int n, State target_state)
{
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        int is_coordinates_valid = 1;

        do
        {

            int x = rand() % this->size;
            int y = rand() % this->size;
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

/*  Checks if a passed coordinate matches any ship position. If so, returns ship coordinate */
Coordinate *Board::search_ship_in_coordinate(int x, int y)
{
    std::string key = std::to_string(x) + std::to_string(y);

    Coordinate *exists = this->ships[key];

    if (exists)
    {
        return exists;
    }

    return NULL;
}

int Board::count_active_ships_coordinates()
{
    return this->active_ships_coordinates;
}