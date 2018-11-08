#ifndef BLINKY_HH
#define BLINKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"
#include "Pacman.hh"

class Blinky: public Character, public Observable<int>{
public:
	Blinky();
	virtual ~Blinky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);
	void move(Pacman & pacman);
protected:
	Event<int>* getEvent();
	mapPath mBlinky;
	
	
};

#endif //BLINKY_HH

