#include "Blinky.hh"

TimeManager &timeManager = TimeManager::GetInstance();

Blinky::Blinky(){
	this->SetLife(1);
}

Blinky::~Blinky(){}

void Blinky::Update(){
	unsigned int value = timeManager.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}