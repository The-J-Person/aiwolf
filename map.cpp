#include "map.h"

map::map(int w, int h)
{
    //ctor
    grid = new int*[h];
    for(int i=0;i<h;i++) grid[i] = new int[w];
    height=h;
    width=w;
}

map::~map()
{
    //dtor
    for(int i=0;i<height;i++) delete(grid[i]);
    delete(grid);

}

map::map(const map& other)
{
    //copy ctor
}

map& map::operator=(const map& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
