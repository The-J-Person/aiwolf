#ifndef BFSWOLF_H
#define BFSWOLF_H

#include "wolf.h"
#include <list>

class BFSwolf : public wolf
{
    public:
        BFSwolf();
        virtual ~BFSwolf();
        direction act();
		std::list<coordinate> get_cords(bool** visited, coordinate cor);
    protected:
    private:
};

#endif // BFSWOLF_H

