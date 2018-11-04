#ifndef INKY_HH
#define INKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"

class Inky: public Character, public Observable<int>{
public:
	Inky();
	virtual ~Inky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);

protected:
	Event<int>* getEvent();
};

#endif //INKY_HH

