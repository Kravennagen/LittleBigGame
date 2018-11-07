#include "GameStatus.hh"

GameStatus::GameStatus(){
	_status = 1;
}

GameStatus::~GameStatus(){}

int GameStatus::GetStatus(){
	return _status;
}

void GameStatus::SetStatus(int status){
	GameStatus::_status = status;
	notify();
}

void GameStatus::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void GameStatus::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* GameStatus::getEvent(){
	return new Event<int>((int *)this->GetStatus());
}