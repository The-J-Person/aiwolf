#include "HunterWolf.h"
#include "map.h"
#include <list>
#include <math.h>
#include <limits.h>

HunterWolf::HunterWolf()
{
	//ctor
}

/*
    the act of the wolf is to move towards the closest rabbit
*/
direction HunterWolf::act()
{
	coordinate cor = get_location();                            //get current location of wolf
	coordinate rcor = parent_map->get_nearest_rabbit(cor);      //get location of closest rabbit

	if (rcor.x == cor.x && rcor.y == cor.y)                     //according to x and y of the rabbit we will move the wolf, towards rabbit
	{
		return NOWHERE;
	}
	else if (rcor.x < cor.x)
	{
		return LEFT;
	}
	else if (rcor.x > cor.x)
	{
		return RIGHT;
	}
	else if (rcor.x == cor.x && cor.y> rcor.y)
	{
		return UP;
	}
	else
	{
		return DOWN;
	}
}
HunterWolf::~HunterWolf()
{
	//dtor
}
