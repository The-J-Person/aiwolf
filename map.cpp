#include "map.h"
#include "lion.h"
#include "rabbit.h"
#include "wolf.h"

map::map(int w, int h, int lchance, int rchance, int tchance, long maxtick)
{
    //ctor
    tick_count=0;
    lion_chance=lchance;
    rabbit_chance=rchance;
    tree_chance=tchance;
    height=h;
    width=w;
    max_ticks=maxtick;
    grid = new map_object*[h];
    for(int i=0;i<h;i++)
    {
        grid[i] = new map_object[w];
        for(int j=0;j<w;j++) generate_terrain(i,j);
    }
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

void map::generate_terrain(int x,int y)
{
    srand (time(NULL));
    int roll = rand() % 100;
    if(roll<lion_chance)
    {
        grid[x][y] = LION;
        lion * L = new lion;
        coordinate c = {x,y};
        L -> set_location(c);
        //animals.add(L);
    }
    else if(roll<lion_chance+rabbit_chance)
    {
        grid[x][y] = RABBIT;
        rabbit * R = new rabbit;
        coordinate c = {x,y};
        R -> set_location(c);
        //animals.add(R);
    }
    else if(roll<lion_chance+rabbit_chance+tree_chance)
    {
        grid[x][y] = TREE;
    }
    else
    {
        grid[x][y] = BLANK;
    }
}

void map::move_map(direction dir)
{
    int x=0;
    int y=0;
    switch(dir)
    {
    case ::UP:
        y=1;
        break;
    case ::RIGHT:
        x=1;
        break;
    case ::DOWN:
        y=-1;
        break;
    case ::LEFT:
        x=-1;
        break;
    case ::NOWHERE:
        break;
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
//            if(i+)
        }
    }
}

void map::draw_map()
{
    for(int i=1;i<height-1;i++)
    {
        for(int j=1;j<width-1;j++)
        {
            char token;
            switch(grid[i][j])
            {
            case TREE:
                token='T';
                break;
            case LION:
                token='L';
                break;
            case RABBIT:
                token='R';
                break;
            case WOLF:
                token='W';
                break;
            default:
                token=' ';
            }
            cout << token;
        }
        cout << endl;
    }
}

long map::run(bool show)
{
    while(tick_count<max_ticks)
    {

        tick_count++;
    }
    return tick_count;
}

coordinate* map::get_all_lions()
{

}
coordinate* map::get_all_rabbits()
{

}

coordinate map::get_nearest_wolf(coordinate source)
{

}

coordinate map::get_nearest_lion(coordinate source)
{

}

coordinate map::get_nearest_rabbit(coordinate source)
{

}

map_object** map::get_grid()
{

}


int map::measure_distance(animal* first,animal* second)
{
    coordinate source=first ->get_location();
    coordinate target=second ->get_location();
    int distx = pow(source.x-target.x,2);
    int disty = pow(source.y-target.y,2);
    int result = sqrt(distx+disty);
    return result;
}
