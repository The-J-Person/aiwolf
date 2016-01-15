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
        for(int j=0; j<w; j++) if(i!=h/2+1 || j!=w/2+1)
            {
                grid[i][j] = BLANK;///Shouldn't be necessary
                generate_terrain(i,j);
            }
    }
    grid[h/2+1][w/2+1] = WOLF;
    animals.push_front(new wolf());
}

map::~map()
{
    //dtor
    for(int i=0; i<height; i++) delete grid[i];
    delete[] grid;
    while(animals.size()>1)
    {
        ///Once size()==1, only the wolf is left, and it is not deleted
        delete animals.back();
        animals.pop_back();
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
    int roll = rand() % 100;
    if(roll<lion_chance)
    {
        grid[x][y] = LION;
        lion * L = new lion;
        coordinate c = {x,y};
        L -> set_location(c);
        L -> set_parent(this);
        animals.push_back(L);
    }
    else if(roll<lion_chance+rabbit_chance)
    {
        grid[x][y] = RABBIT;
        rabbit * R = new rabbit;
        coordinate c = {x,y};
        R -> set_location(c);
        R -> set_parent(this);
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
    switch(dir) ///Reverse, because if the wolf moved right, the map moves left, etc
    {
    case ::UP:
        y=1;
        break;
    case ::RIGHT:
        x=-1;
        break;
    case ::DOWN:
        y=-1;
        break;
    case ::LEFT:
        x=1;
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
                {
                    coordinate c = {i,j};
                    animal* local = find_animal_by_location(c);
                    c.x=i+y;
                    c.y=j+x;
                    if(local!=NULL) local -> set_location(c);
                    swap(grid[i][j],grid[i+y][j+x]);
                }
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
    delete animals.front();
    animals.pop_front();
    coordinate c = {height/2+1,width/2+1};
    protag -> set_location(c);
    protag -> set_parent(this);
    animals.push_front(protag);
}

long map::run(bool show)
{
    wolf * p = (wolf*)(animals.front());
    while(tick_count<max_ticks && !(p->starve()))
    {
        ///Move everyone
        list<animal*>::iterator it;
        coordinate c;
        for (it=animals.begin(); it!=animals.end() ; ++it)
        {
            direction d = (*it) -> act();
            c = (*it) -> get_location();
            int x = c.x;
            int y = c.y;
            int modx=0;
            int mody=0;
            switch(d)
            {
            case UP:
                modx=-1;
                break;
            case DOWN:
                modx=1;
                break;
            case RIGHT:
                mody=1;
                break;
            case LEFT:
                mody=-1;
                break;
            case NOWHERE:
                break;
            }
            if((x==0 && modx==-1) || (y==0 && mody==-1) || (x==height-1 && modx==1) || (y==width-1 && mody==1))
            {
                ///If the animal left the map...
                animal * ptr = (*it);
                --it;//This is safe, because the wolf never leaves the map, and is always first in the list
                animals.remove(ptr);
                delete ptr;
            }
            else if(modx!=0 || mody!=0)switch(grid[x][y])
                {
                case WOLF:
                    switch(grid[x+modx][y+mody])
                    {
                    case WOLF:
                        cout << "The developer did not account for 2 wolves on the same map!" << endl;
                        break;
                    case RABBIT:
                    {
                        c.x=x+modx;
                        c.y=y+mody;
                        animal * ptr = find_animal_by_location(c);
                        animals.remove(ptr);
                        delete ptr;
                        (*it) -> set_location(c);
                        swap(grid[x][y],grid[x+modx][y+mody]);
                        grid[x][y]=BLANK;
                        move_map(d);
                        p -> eat();
                    }
                    break;
                    case LION:
                        ///The Wolf gets himself killed
                        return tick_count;
                    case TREE:
                        break;
                    case BLANK:
                        c.x=x+modx;
                        c.y=y+mody;
                        (*it) -> set_location(c);
                        swap(grid[x][y],grid[x+modx][y+mody]);
                        move_map(d);
                        break;
                    }
                    if(show)
                    {
                        draw_map();
                        cin.ignore();
                    }
                    break;

                case LION:
                    switch(grid[x+modx][y+mody])
                    {
                    case WOLF:
                        ///The wolf has been eaten
                        return tick_count;
                        break;
                    case RABBIT:
                        ///Don't move, you might step on the rabbit!
                        break;
                    case LION:
                        ///Don't move, you'll make the other lion angry
                        break;
                    case TREE:
                        ///The lion hits a tree! Ow!
                        break;
                    case BLANK:
                        c.x=x+modx;
                        c.y=y+mody;
                        (*it) -> set_location(c);
                        swap(grid[x][y],grid[x+modx][y+mody]);
                        break;
                    }

                case RABBIT:
                    switch(grid[x+modx][y+mody])
                    {
                    case WOLF:
                        ///The rabbit sacrificed himself. Should not happen.
                    {
                        p -> eat();
                        animal* ptr=(*it);
                        --it;
                        delete ptr;
                    }
                    grid[x][y]=BLANK;
                    break;
                    case RABBIT:
                        ///Don't move, the other rabbit is in the way
                        break;
                    case LION:
                        ///Don't move, you'll make the lion angry!
                        break;
                    case TREE:
                        ///The rabbit hits a tree! Ow!
                        break;
                    case BLANK:
                        c.x=x+modx;
                        c.y=y+mody;
                        (*it) -> set_location(c);
                        swap(grid[x][y],grid[x+modx][y+mody]);
                        break;
                    }
                default:
                    break;
                }
            else if(show && (*it)==p)
            {
                draw_map();
                cin.ignore();
            }
        }
        ///
        p -> grow_hungry();
        generate_edges();
        tick_count++;
    }
    return tick_count;
}

list<coordinate> map::get_all_lions()
{
    list<animal*>::iterator it;
    list<coordinate> lions;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        coordinate loc = (*it)->get_location();
        if(grid[loc.x][loc.y]==LION) lions.push_front((*it)->get_location());
    }
    return lions;
}
list<coordinate> map::get_all_rabbits()
{
    list<animal*>::iterator it;
    list<coordinate> rabbits;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        coordinate loc = (*it)->get_location();
        if(grid[loc.x][loc.y]==RABBIT) rabbits.push_front((*it)->get_location());
    }
    return rabbits;
}

coordinate map::get_nearest_wolf(coordinate source)
{
    list<animal*>::iterator it;
    int dist=0;
    int mindist=width+height;
    coordinate mindistcoor=source;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        coordinate loc = (*it)->get_location();
        if(grid[loc.x][loc.y]==WOLF)
        {
            dist=measure_distance(source,loc);
            if(dist<mindist&&dist!=0)
            {
                mindistcoor=loc;
                mindist=dist;
            }
        }
    }
    return mindistcoor;
}

coordinate map::get_nearest_lion(coordinate source)
{
    list<animal*>::iterator it;
    int dist=0;
    int mindist=width+height;
    coordinate mindistcoor=source;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        coordinate loc = (*it)->get_location();
        if(grid[loc.x][loc.y]==RABBIT)
        {
            dist=measure_distance(source,loc);
            if(dist<mindist&&dist!=0)
            {
                mindistcoor=loc;
                mindist=dist;
            }
        }
    }
    return mindistcoor;
}

coordinate map::get_nearest_rabbit(coordinate source)
{
    list<animal*>::iterator it;
    int dist=0;
    int mindist=width+height;
    coordinate mindistcoor=source;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        coordinate loc = (*it)->get_location();
        if(grid[loc.x][loc.y]==RABBIT)
        {
            dist=measure_distance(source,loc);
            if(dist<mindist&&dist!=0)
            {
                mindistcoor=loc;
                mindist=dist;
            }
        }
    }
    return mindistcoor;
}

map_object** map::get_grid()
{
    return grid;
}


int map::measure_distance(coordinate source,coordinate target)
{
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

animal* map::find_animal_by_location(coordinate c)
{
    list<animal*>::iterator it;
    for (it=animals.begin(); it!=animals.end() ; ++it)
    {
        if((*it)->get_location().x==c.x && (*it)->get_location().y==c.y ) return (*it);
    }
    return NULL;
}
