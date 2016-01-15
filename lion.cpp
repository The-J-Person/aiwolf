#include "lion.h"
#include "map.h"

lion::lion()
{
    //ctor
}

direction lion::act()
{
    coordinate cor = get_location();
	coordinate wcor = parent_map->get_nearest_wolf(cor);

	if (wcor.x == cor.x && wcor.y == cor.y)
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
