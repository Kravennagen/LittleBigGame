#include "Clyde.hh"

TimeManager &timeManager = TimeManager::GetInstance();

Clyde::Clyde(){
	this->SetLife(1);
}

Clyde::~Clyde(){}

void Clyde::Update(){
	unsigned int value = timeManager.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}