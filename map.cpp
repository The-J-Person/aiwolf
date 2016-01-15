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
    for(int i=0; i<h; i++)
    {
        grid[i] = new map_object[w];
        for(int j=0; j<w; j++) if(i!=h/2+1 && j!=w/2+1)generate_terrain(i,j);
    }
    grid[h/2+1][w/2+1] = WOLF;
    wolf * def = new wolf();
    animals.push_front(def);
}

map::~map()
{
    //dtor
    for(int i=0; i<height; i++) delete(grid[i]);
    delete(grid);
    while(!animals.empty())
    {
        delete animals.front();
        animals.pop_front();
    }
}

map::map(const map& other)
{
    //"copy" ctor
    tick_count=0;
    lion_chance=other.lion_chance;
    rabbit_chance=other.rabbit_chance;
    tree_chance=other.tree_chance;
    height=other.height;
    width=other.width;
    max_ticks=other.max_ticks;
    grid = new map_object*[height];
    for(int i=0; i<height; i++)
    {
        grid[i] = new map_object[width];
        for(int j=0; j<width; j++) if(i!=height/2+1 && j!=width/2+1)generate_terrain(i,j);
    }
    grid[height/2+1][width/2+1] = WOLF;
    wolf * def = new wolf();
    animals.push_front(def);
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
        animals.push_back(L);
    }
    else if(roll<lion_chance+rabbit_chance)
    {
        grid[x][y] = RABBIT;
        rabbit * R = new rabbit;
        coordinate c = {x,y};
        R -> set_location(c);
        animals.push_back(R);
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
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i+y<height && i+y>=0)
                if(j+x<width && j+x>=0)
                    swap(grid[i][j],grid[i+y][j+x]);
        }
    }
}

void map::draw_map()
{
    for(int i=1; i<height-1; i++)
    {
        for(int j=1; j<width-1; j++)
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

void map::placewolf(wolf* protag)
{
    animals.pop_front();
    animals.push_front(protag);
}

long map::run(bool show)
{
    while(tick_count<max_ticks)
    {
        ///Move everyone
        ///Gotta put an iterator here
        generate_edges();
        tick_count++;
    }
    return tick_count;
}

list<coordinate> map::get_all_lions()
{

}
list<coordinate> map::get_all_rabbits()
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
    return grid;
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

void map::generate_edges()
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i==height-1 || j==width-1 || i==0 || j==0) generate_terrain(i,j);
        }
    }
}
