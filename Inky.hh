#ifndef INKY_HH
#define INKY_HH

#include "TimeManager.hh"
#include "Character.hh"

class Inky: public Character{
public:
	Inky();
	virtual ~Inky();

	virtual void Update();
};

#endif //INKY_HH

