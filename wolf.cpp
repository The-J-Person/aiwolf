#include "wolf.h"

wolf::wolf()
{
    //ctor
}

int wolf::act()
{
    return 0;
}
wolf::~wolf()
{
    //dtor
}

void wolf::set_hunger_threshold(int newthresh)
{
    hunger_threshold=newthresh;
}

void wolf::grow_hungry()
{
    hunger++;
}
