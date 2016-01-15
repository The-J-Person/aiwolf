#ifndef STUPIDWOLF_H
#define STUPIDWOLF_H

#include "wolf.h"


class StupidWolf : public wolf
{
    public:
        StupidWolf();
        virtual ~StupidWolf();
        virtual direction act();
    protected:

    private:
};

#endif // STUPIDWOLF_H
