#include "BFSWolf.h"
#include "map.h"
#include <queue>

BFSWolf::BFSWolf()
{
    //ctor
}

BFSWolf::~BFSWolf()
{
    //dtor
}

direction BFSWolf::act()
{
    map_object** mp = parent_map->get_grid();           //get current map
    coordinate start = get_location();                  //get coordinates of current wolf
    const int width = start.x * 2 - 1;                  //get width/height of map
    const int height = start.y * 2 - 1;
    std::queue<coordinate> que;

    bool** visited = new bool*[width];                  //2d array for visitation of cells set to not visited
    for (int i = 0; i < width; i++)
    {
        visited[i] = new bool[height];
        for (int j = 0; j < height; j++)
            visited[i][j] = false;
    }
    que.push(start);                                    //push first coordinate of current wolf
    visited[start.x][start.y] = true;
    while(!que.empty())
    {
        coordinate cor = que.front();
        std::list<coordinate> cors = get_cords(visited,cor);
        for (list<coordinate>::const_iterator ci = cors.begin(); ci != cors.end(); ++ci)
        {
            if (mp[ci->x][ci->y] == RABBIT)             //check on which direction to go
            {
                if (ci->x == start.x && ci->y == start.y)
                {
                    return NOWHERE;
                }
                else if (ci->x < start.x)
                {
                    return LEFT;
                }
                else if (ci->x < start.x)
                {
                    return RIGHT;
                }
                else if (ci->x == start.x && start.y> ci->y)
                {
                    return UP;
                }
                else
                {
                    return DOWN;
                }
            }
            visited[ci->x][ci->y] = true;               //set visitation to visited
        }
    }
    return NOWHERE;
}
/*
    determine what coordinated to add to bfs
*/
std::list<coordinate> BFSWolf::get_cords(bool** visited, coordinate cor)
{

    std::list<coordinate> cors;
    if (cor.x > 0 && visited[cor.x - 1][cor.y] == false)
    {
        coordinate c = { cor.x - 1, cor.y };
        cors.push_back(c);
    }
    if (cor.x< get_location().x * 2 - 1 && visited[cor.x + 1][cor.y] == false)
    {
        coordinate c = { cor.x + 1, cor.y };
        cors.push_back(c);
    }
    if (cor.y>0 && visited[cor.x][cor.y - 1] == false)
    {
        coordinate c = { cor.x, cor.y - 1 };
        cors.push_back(c);
    }
    if (cor.y < get_location().y * 2 - 1 && visited[cor.x][cor.y + 1] == false)
    {
        coordinate c = { cor.x, cor.y + 1 };
        cors.push_back(c);
    }
    return cors;
}
