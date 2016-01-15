#ifndef BFSWOLF_H
#define BFSWOLF_H

#include "wolf.h"
#include <list>

/*
    header file for the BFS wolf
    a wolf that looks for the closes rabbit using a BFS graph
    no attention to lions
*/
class BFSWolf : public wolf
{
    public:
        BFSWolf();
        virtual ~BFSWolf();
        direction act();
		std::list<coordinate> get_cords(bool** visited, coordinate cor);
    protected:
    private:
};

#endif // BFSWOLF_H

