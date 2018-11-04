#ifndef PACMAN_HH
#define PACMAN_HH

#include "TimeManager.hh"
#include "Character.hh"
#include "Observable.hpp"

class Pacman: public Observable<int>, public Character {
public:
	Pacman();
	~Pacman();

	virtual void Update();

	void addObserver(Observer<int>* obs);

	void removeObserver(Observer<int>* obs);

	void PacmanDied();

protected:
	Event<int>* getEvent();
};

#endif //PACMAN_HH