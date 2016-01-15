#include "wolf.h"

wolf::wolf()
{
    //ctor
    hunger=0;
    hunger_threshold=0;
}

direction wolf::act()
{
    return NOWHERE;
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

void wolf::eat()
{
    hunger=0;
}

bool wolf::starve()
{
    if(hunger<hunger_threshold) return false;
    return true;
}
