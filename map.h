#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <cstdlib>
#include <list>
#include <cmath>
#include "misc.h"
using namespace std;

class animal;
class wolf;

class map
{
    public:
        map(int, int, int, int, int, long);
        ~map();
        map(const map& other);
        map& operator=(const map& other);
        void draw_map();
        void placewolf(wolf* protag);
        long run(bool); ///Returns number of steps before wolf death. Takes a TRUE is the operator should view every step.

        list<coordinate> get_all_lions();
        list<coordinate> get_all_rabbits();
        coordinate get_nearest_wolf(coordinate source);
        coordinate get_nearest_lion(coordinate source);
        coordinate get_nearest_rabbit(coordinate source);
        map_object** get_grid();
//        int** Getgrid() { return grid; }
//        void Setgrid(int** val) { grid = val; }

    protected:

    private:
        map_object** grid; ///Map's grid
        list<animal*> animals; ///Action queue of actors
        long tick_count; ///Number of actions the wolf took
        long max_ticks; ///Point to stop simulation
        int height;
        int width;
        int lion_chance;
        int rabbit_chance;
        int tree_chance;

        void move_map(direction);
        void generate_edges();
        void generate_terrain(int,int);
        int measure_distance(animal*,animal*);
};

#endif // MAP_H
