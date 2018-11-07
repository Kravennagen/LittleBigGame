#ifndef CLYDE_HH
#define CLYDE_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"

class Clyde: public Character, public Observable<int>{
public:
	Clyde();
	virtual ~Clyde();

	virtual void Update();
	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);
	void move();
protected:
	Event<int>* getEvent();
	mapPath mClyde;
	
	aStar asClyde;
};

#endif //CLYDE_HH

