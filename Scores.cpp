#include "Scores.hh"

Scores::Scores(){
	_scores = 0;
}

Scores::~Scores(){}

int Scores::GetScores() const {
	return _scores;
}

void Scores::SetScores(int _Scores){
	Scores::_scores = _Scores;
}

void Scores::AddPoint(int points){
	SetScores(GetScores() + points);
	notify();
}

void Scores::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Scores::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Scores::getEvent(){
	return new Event<int>((int *)this->GetScores());
}

