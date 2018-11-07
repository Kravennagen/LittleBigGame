#include "Clyde.hh"

TimeManager &timeManagerClyde = TimeManager::GetInstance();

Clyde::Clyde(){
	this->SetLife(1);
	this->SetX(0);
	this->SetY(0);
}

Clyde::~Clyde(){}

void Clyde::Update(){
	unsigned int value = timeManagerClyde.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Clyde::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Clyde::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Clyde::getEvent(){
	return new Event<int>((int *)this->GetLife());
}