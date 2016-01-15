#include "lion.h"
#include "map.h"

lion::lion()
{
    //ctor
}

/*
    the act of the lion is to move towards the closest wolf
*/
direction lion::act()
{
    coordinate cor = get_location();                            //get current location of lion
	coordinate wcor = parent_map->get_nearest_wolf(cor);        //get location of closest wolf

	if (wcor.x == cor.x && wcor.y == cor.y)                     //according to x and y of the wolf we will move the lion, towards wolf
	{
		return NOWHERE;
	}
	else if (wcor.x < cor.x)
	{
		return LEFT;
	}
	else if (wcor.x > cor.x)
	{
		return RIGHT;
	}
	else if (wcor.x == cor.x && cor.y> wcor.y)
	{
		return UP;
	}
	else
	{
		return DOWN;
	}
}
lion::~lion()
{
    //dtor
}
