#include "rabbit.h"
#include "map.h"

rabbit::rabbit()
{
    //ctor
}

/*
    the act of the rabbit is to run away from the nearest wolf
*/
direction rabbit::act()
{
    coordinate cor = get_location();                        //get current location of rabbit
	coordinate wcor = parent_map->get_nearest_wolf(cor);    //get location of closest wolf

	if (wcor.x == cor.x && wcor.y == cor.y)                 //according to x and y of the wolf we will move the rabbit, away from the wolf
	{
		return NOWHERE;
	}
	else if (wcor.x < cor.x)
	{
		return RIGHT;
	}
	else if (wcor.x > cor.x)
	{
		return LEFT;
	}
	else if (wcor.x == cor.x && cor.y> wcor.y)
	{
		return DOWN;
	}
	else
	{
		return UP;
	}
}
rabbit::~rabbit()
{
    //dtor
}
