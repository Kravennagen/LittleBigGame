#include "Balls.hh"

Balls::Balls(){}

Balls::~Balls(){}

int Balls::BallsWasEat(int tile, Scores &scores, GameStatus &gameStatus){
	
	if(tile == 2){
		scores.AddPoint(1);
		SetTotalBalls(GetTotalBalls() + 1);
	}else if(tile == 3){
		scores.AddPoint(2);
		SetTotalBalls(GetTotalBalls() + 1);
	}

	if(GetTotalBalls() == 244){
		gameStatus.SetStatus(0);
	}
	return 0;
}

int Balls::GetTotalBalls(){
	return _totalBalls;
}

void Balls::SetTotalBalls(int totalBalls){
	Balls::_totalBalls = totalBalls;
	notify();
}

void Balls::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Balls::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Balls::getEvent(){
	return new Event<int>((int *)this->GetTotalBalls());
}