#include "animal.h"
#include "map.h"

animal::animal()
{
    //ctor
}

direction animal::act()
{
    return NOWHERE;
}

void animal::set_parent(map* parent)
{
    parent_map=parent;
}

//void animal::move_self(direction D)
//{
//    switch(D)
//    {
//    case UP:
//        loc.y++;
//        break;
//    case RIGHT:
//        loc.x++;
//        break;
//    case DOWN:
//        loc.y--;
//        break;
//    case LEFT:
//        loc.x--;
//        break;
//    case NOWHERE:
//        break;
//    }
//}

coordinate animal::get_location()
{
    return loc;
}

void animal::set_location(coordinate c)
{
    loc=c;
}

animal::~animal()
{
    //dtor
}
