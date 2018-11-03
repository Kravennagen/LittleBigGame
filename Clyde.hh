#ifndef CLYDE_HH
#define CLYDE_HH

#include "TimeManager.hh"
#include "Character.hh"

class Clyde: public Character{
public:
	Clyde();
	virtual ~Clyde();

	virtual void Update();
};

#endif //CLYDE_HH

