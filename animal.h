#ifndef ANIMAL_H
#define ANIMAL_H

#include "misc.h"
class animal
{
    public:
        animal();
        virtual ~animal();
        virtual int act();
        void move_self(direction);
        coordinate get_location();
    protected:
    private:
        coordinate loc;
};

#endif // ANIMAL_H
