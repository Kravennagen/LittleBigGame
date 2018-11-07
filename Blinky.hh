#ifndef BLINKY_HH
#define BLINKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"
#include "Path2.cpp"

class Blinky: public Character, public Observable<int>{
public:
	Blinky();
	virtual ~Blinky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);
	void move();
protected:
	Event<int>* getEvent();
	mapPath m;
	
	aStar as;
};

#endif //BLINKY_HH

