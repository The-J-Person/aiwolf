#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <queue>
#include "animal.h"
#include "misc.h"
using namespace std;

class map
{
    public:
        map(int, int);
        ~map();
        map(const map& other);
        map& operator=(const map& other);
        void add_animal(animal&);
        void move_map(direction);
//        int** Getgrid() { return grid; }
//        void Setgrid(int** val) { grid = val; }

    protected:

    private:
        int** grid;
        queue<animal> animals;
        int tick_count;
        int height;
        int width;
        void generate_terrain();
};

#endif // MAP_H
