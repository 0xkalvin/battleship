#include "board.h"

Board::Board(int size){
    this->size = size;
    this->state = (Coordinate ***)malloc(this->size * sizeof(Coordinate **));

    for (int i = 0; i < this->size ; i++)
    {
        this->state[i] = (Coordinate **)malloc(this->size  * sizeof(Coordinate*));

        for (int j = 0; j < this->size ; j++)
        {
            this->state[i][j] = (Coordinate *)malloc(this->size  * sizeof(Coordinate));
            this->state[i][j]->x = i;
            this->state[i][j]->y = j;

        }
    }

}

Board::~Board(){
    delete this->state;
}