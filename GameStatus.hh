#ifndef GAMESTATUS_HH
#define GAMESTATUS_HH

#include "Observable.hpp"
#include <iostream>

class GameStatus: public Observable<int>{
public:
	GameStatus();
	~GameStatus();
	int _status;
	int GetStatus();
	void SetStatus(int status);
	void addObserver(Observer<int>* obs);
	void removeObserver(Observer<int>* obs);
private:
	Event<int>* getEvent();
};

#endif // GAMESTATUS_HH