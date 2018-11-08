#ifndef PINKY_HH
#define PINKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include <iostream>
#include "Observable.hpp"
#include "Pacman.hh"

class Pinky : public Observable<int>, public Character
{
public:
	Pinky();
	virtual ~Pinky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);

	void CheckPosition(int _x, int _y, int level[31][28]);
	void move(Pacman &pacman);

protected:
	Event<int>* getEvent();
	mapPath mPinky;
	
	aStar asPinky;
};

#endif //PINKY_HH

