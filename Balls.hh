#ifndef BALLS_HH
#define BALLS_HH

#include "Scores.hh"
#include "GameStatus.hh"

class Balls: public Observable<int>{
public:
	Balls();
	~Balls();
	int BallsWasEat(int tile, Scores &scores, GameStatus &gameStatus);
	int _totalBalls;
	int GetTotalBalls();
	void SetTotalBalls(int _totalBallsBalls);
	void addObserver(Observer<int>* obs);
	void removeObserver(Observer<int>* obs);
private:
	Event<int>* getEvent();

};

#endif // BALLS_HH