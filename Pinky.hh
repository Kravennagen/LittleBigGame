#ifndef PINKY_HH
#define PINKY_HH

#include "TimeManager.hh"
#include "Character.hh"

class Pinky: public Character{
public:
	Pinky();
	virtual ~Pinky();

	virtual void Update();
};

#endif //PINKY_HH

