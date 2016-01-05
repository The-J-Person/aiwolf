#ifndef WOLF_H
#define WOLF_H

#include "animal.h"


class wolf : public animal
{
    public:
        wolf();
        virtual ~wolf();
        virtual int act();
    protected:
    private:
        int hunger;
        int hunger_threshold;
};

#endif // WOLF_H
