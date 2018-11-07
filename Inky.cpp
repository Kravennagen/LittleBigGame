#include "Inky.hh"

TimeManager &timeManagerInky = TimeManager::GetInstance();

Inky::Inky(){
	this->SetLife(1);
	this->SetX(0);
	this->SetY(0);
}

Inky::~Inky(){}

void Inky::Update(){
	unsigned int value = timeManagerInky.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Inky::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Inky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Inky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}