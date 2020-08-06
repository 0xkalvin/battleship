#include "board.h"

Board::Board(int size){
    this->size = size;
    this->grid = (Coordinate ***)malloc(this->size * sizeof(Coordinate **));

    for (int i = 0; i < this->size ; i++)
    {
        this->grid[i] = (Coordinate **)malloc(this->size  * sizeof(Coordinate *));

        for (int j = 0; j < this->size ; j++)
        {
            this->grid[i][j] = (Coordinate *)malloc(this->size  * sizeof(Coordinate));
            this->grid[i][j]->x = i;
            this->grid[i][j]->y = j;
            this->grid[i][j]->state = 0;
        }
    }

}

Board::~Board(){
    delete this->grid;
}