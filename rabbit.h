#ifndef RABBIT_H
#define RABBIT_H

#include "animal.h"


class rabbit : public animal
{
    public:
        rabbit();
        virtual ~rabbit();
        int act();
    protected:

    private:
};

#endif // RABBIT_H
