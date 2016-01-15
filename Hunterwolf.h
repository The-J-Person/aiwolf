#ifndef HUNTERWOLF_H
#define HUNTERWOLF_H

#include "wolf.h"


class HunterWolf : public wolf
{
public:
	HunterWolf();
	virtual ~HunterWolf();
	int act();
protected:

private:
};

#endif // HUNTERWOLF_H
