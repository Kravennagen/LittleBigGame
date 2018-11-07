#include "Scores.hh"

Scores::Scores(){
	SetScores(0);
}

Scores::~Scores(){}

int Scores::GetScores() {
	return _scores;
}

void Scores::SetScores(int _Scores){
	Scores::_scores = _Scores;
	notify();
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

