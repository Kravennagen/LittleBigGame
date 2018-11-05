#ifndef PINKY_HH
#define PINKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include <iostream>
#include "Observable.hpp"


class Pinky : public Observable<int>, public Character
{
public:
	Pinky();
	virtual ~Pinky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);

	void CheckPosition(int _x, int _y, int level[31][28]);

protected:
	Event<int>* getEvent();
};

#endif //PINKY_HH

