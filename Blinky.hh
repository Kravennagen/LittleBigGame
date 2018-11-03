#ifndef BLINKY_HH
#define BLINKY_HH

#include "TimeManager.hh"
#include "Character.hh"

class Blinky: public Character{
public:
	Blinky();
	virtual ~Blinky();

	virtual void Update();
};

#endif //BLINKY_HH

