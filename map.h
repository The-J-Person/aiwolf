#ifndef MAP_H
#define MAP_H
#include "animal.h"
#include <iostream>
#include <queue>
using namespace std;

class map
{
    public:
        map(int, int);
        ~map();
        map(const map& other);
        map& operator=(const map& other);

//        int** Getgrid() { return grid; }
//        void Setgrid(int** val) { grid = val; }

    protected:

    private:
        int** grid;
        queue<animal> animals;
        int tick_count;
        int height;
        int width;
};

#endif // MAP_H
