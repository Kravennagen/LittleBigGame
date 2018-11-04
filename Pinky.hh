#ifndef PINKY_HH
#define PINKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"


class Pinky : public Observable<int>, public Character
{
public:
	Pinky();
	virtual ~Pinky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);

protected:
	Event<int>* getEvent();
};

#endif //PINKY_HH

