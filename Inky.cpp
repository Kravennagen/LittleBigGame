#include "Inky.hh"

TimeManager &timeManager = TimeManager::GetInstance();

Inky::Inky(){
	this->SetLife(1);
}

Inky::~Inky(){}

void Inky::Update(){
	unsigned int value = timeManager.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}