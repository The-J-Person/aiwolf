#ifndef BFSWOLF_H
#define BFSWOLF_H

#include "wolf.h"
#include <list>

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

