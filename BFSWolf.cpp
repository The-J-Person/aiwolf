
#include "BFSWolf.h"
#include <queue>
#include <list>

BFSwolf::BFSwolf()
{
    //ctor
    int width = parent_map.width;
    int height = parent_map.height;
    coordinate start = this.get_location();
    std::queue<coordinate> que;
    bool visited[width][height] = {false}
}

BFSwolf::~BFSwolf()
{
    //dtor
}

int BFSwolf::act()
{
    que.push(start);
    set_visit(start);
    while(!que.empty())
    {
        coordinate cor = que.pop();
        std::list<coordinate> cors = get_cords(cor);
        for (i=0;i<cors.size();i++)
        {
            if(parent_map[cors[i].x][cors[i].y] == RABBIT)
                move_self()///needd to determine what direction
                return o;
            set_visit(cors[i]);
        }
    }
}
void BFSwolf::set_visit(coordinate cor)
{
    visited[cor.x][cor.y] = 1;
}

list<coordinate> BFSwolf::get_cords(coordinate cor)
{
    std::list<coordinate> cors;
    if(cor.x>0 and visited[x-1][y] == true)
        cors.push_back(new coordinate(x-1,y));
    if(cor.x<height and visited[x+1][y] == true)
        cors.push_back(new coordinate(x+1,y));
    if(cor.y>0 and visited[x][y-1] == true)
        cors.push_back(new coordinate(x,y-1));
    if(cor.y<height and visited[x][y+1] == true)
        cors.push_back(new coordinate(x,y+1));
    return cors;
}
