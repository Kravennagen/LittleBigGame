#include "Pinky.hh"

TimeManager &timeManager = TimeManager::GetInstance();

Pinky::Pinky(){
	this->SetLife(1);
}

Pinky::~Pinky(){}

void Pinky::Update(){
	unsigned int value = timeManager.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}