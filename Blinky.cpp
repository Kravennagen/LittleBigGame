#include "Blinky.hh"

TimeManager &timeManagerBlinky = TimeManager::GetInstance();

Blinky::Blinky(){
	this->SetLife(1);
	
}

Blinky::~Blinky(){}

void Blinky::Update(){
	unsigned int value = timeManagerBlinky.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Blinky::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
		std::cout << "+1 observer" << std::endl;
}

void Blinky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
		std::cout << "-1 observer" << std::endl;
}

Event<int>* Blinky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}


