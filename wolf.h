#ifndef WOLF_H
#define WOLF_H

#include "animal.h"


class wolf : public animal
{
    public:
        wolf();
        virtual ~wolf();
        virtual direction act();
        void set_hunger_threshold(int);
        void grow_hungry();
    protected:
    private:
        int hunger;
        int hunger_threshold;
};

#endif // WOLF_H
