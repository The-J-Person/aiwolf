
#include "BFSWolf.h"
#include "map.h"
#include <queue>

BFSwolf::BFSwolf()
{
    //ctor
	dead = false;
}

BFSwolf::~BFSwolf()
{
    //dtor
}

direction BFSwolf::act()
{
	map_object** mp = parent_map->get_grid();
	coordinate start = get_location();
	const int width = start.x * 2 - 1;
	const int height = start.y * 2 - 1;
	std::queue<coordinate> que;

	bool** visited = new bool*[width];
	for (int i = 0; i < width; i++)
	{
		visited[i] = new bool[height];
		for (int j = 0; j < height; j++)
			visited[i][j] = false;
	}
    que.push(start);
	visited[start.x][start.y] = true;
    while(!que.empty())
    {
        coordinate cor = que.front();
        std::list<coordinate> cors = get_cords(visited,cor);
		for (list<coordinate>::const_iterator ci = cors.begin(); ci != cors.end(); ++ci)
        {
            if(mp[ci->x][ci->y] == RABBIT)
                return UP;
			visited[ci->x][ci->y] = true;
        }
    }
}

std::list<coordinate> BFSwolf::get_cords(bool** visited, coordinate cor)
{

	std::list<coordinate> cors;
	if (cor.x > 0 && visited[cor.x - 1][cor.y] == true)
		cors.push_back(coordinate{ cor.x - 1, cor.y });
	if (cor.x< get_location().x*2-1 && visited[cor.x + 1][cor.y] == true)
		cors.push_back(coordinate{ cor.x + 1, cor.y });
	if (cor.y>0 && visited[cor.x][cor.y - 1] == true)
		cors.push_back(coordinate{ cor.x, cor.y - 1 });
	if (cor.y < get_location().x * 2 - 1 && visited[cor.x][cor.y + 1] == true)
		cors.push_back(coordinate{ cor.x, cor.y + 1 });
    return cors;
}
