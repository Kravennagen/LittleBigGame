#ifndef INKY_HH
#define INKY_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"
#include "Pacman.hh"

class Inky: public Character, public Observable<int>{
public:
	Inky();
	virtual ~Inky();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);
	void move(Pacman &pacman);
protected:
	Event<int>* getEvent();
	mapPath mInky;
	
	aStar asInky;
};

#endif //INKY_HH

