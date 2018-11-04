#include "Pinky.hh"

TimeManager &timeManagerPinky = TimeManager::GetInstance();

Pinky::Pinky(){
	this->SetLife(1);
	//this->SetX(0);
	//this->SetY(0);
}

Pinky::~Pinky(){}

void Pinky::Update(){
	unsigned int value = timeManagerPinky.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Pinky::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
		std::cout << "+1 observer" << std::endl;
}

void Pinky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
		std::cout << "-1 observer" << std::endl;
}

Event<int>* Pinky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}