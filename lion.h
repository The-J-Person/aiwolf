#ifndef LION_H
#define LION_H

#include "animal.h"


class lion : public animal
{
    public:
        lion();
        virtual ~lion();
        direction act();
    protected:

    private:
};

#endif // LION_H
