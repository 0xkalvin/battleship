#include "coordinate.h"

Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
    this->state = UNKNOWN;
}

Coordinate::Coordinate(int x, int y, State state){
    this->x = x;
    this->y = y;
    this->state = state;
}

Coordinate::~Coordinate(){}

int Coordinate::operator==(Coordinate *c){
    return c->x == this->x && c->y == this->y;
}

std::ostream& operator<<(std::ostream& out, const Coordinate& c)
{
    out << "( " << c.x << ", " << c.y << " ) -> " << c.state << '\n';
    return out;
}
