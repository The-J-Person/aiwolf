#ifndef ANIMAL_H
#define ANIMAL_H

#include "misc.h"
class map;

class animal
{
    public:
        animal();
        virtual ~animal();
        virtual direction act();
        //void move_self(direction);
        void set_location(coordinate);
        coordinate get_location();
    protected:
        bool dead;
        map* parent_map;
    private:
        coordinate loc;
};

#endif // ANIMAL_H
