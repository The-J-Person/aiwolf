#ifndef STUPIDWOLF_H
#define STUPIDWOLF_H

#include "wolf.h"


class StupidWolf : public wolf
{
    public:
        StupidWolf();
        virtual ~StupidWolf();
        virtual int act();
    protected:

    private:
};

#endif // STUPIDWOLF_H
