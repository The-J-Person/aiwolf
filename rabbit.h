#ifndef RABBIT_H
#define RABBIT_H

#include "animal.h"
#include <list>


class rabbit : public animal
{
    public:
        rabbit();
        virtual ~rabbit();
        direction act();
    protected:

    private:
};

#endif // RABBIT_H
