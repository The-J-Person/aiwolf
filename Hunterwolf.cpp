#include "Hunterwolf.h"
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
	coordinate cor, mincor;
	list<float> dists;
	list<coordinate> cors = parent_map->get_all_rabbits();
	int x, y;
	float res, min = INT_MAX;
	cor = mincor = get_location();
	for (list<coordinate>::const_iterator ci = cors.begin(); ci != cors.end(); ++ci)
	{
		x = cor.x - ci->x;
		y = cor.y - ci->y;
		res = ((y*y) / (x*x));
		dists.push_back(sqrt(res));
		if (res < min)
		{
			min = res;
			mincor = {ci->x, ci->y};
		}
	}
	if (mincor.x == cor.x && mincor.y == cor.y)
	{
		return NOWHERE;
	}
	else if (mincor.x < cor.x)
	{
		return LEFT;
	}
	else if (mincor.x < cor.x)
	{
		return RIGHT;
	}
	else if (mincor.x == cor.x && cor.y> mincor.y)
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
