#include "HunterWolf.h"
#include "map.h"
#include <list>
#include <math.h>
#include <limits.h>

HunterWolf::HunterWolf()
{
	//ctor
}

direction HunterWolf::act()
{
	coordinate cor = get_location();
	coordinate rcor = parent_map->get_nearest_rabbit(cor);

	if (rcor.x == cor.x && rcor.y == cor.y)
	{
		return NOWHERE;
	}
	else if (rcor.x < cor.x)
	{
		return LEFT;
	}
	else if (rcor.x < cor.x)
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
