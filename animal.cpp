#include "animal.h"

animal::animal()
{
    //ctor
}

int animal::act()
{

}

void animal::move_self(direction D)
{
    switch(D)
    {
    case up:
        loc.y++;
        break;
    case right:
        loc.x++;
        break;
    case down:
        loc.y--;
        break;
    case left:
        loc.x--;
        break;
    }
}

coordinate animal::get_location()
{
    return loc;
}

animal::~animal()
{
    //dtor
}
