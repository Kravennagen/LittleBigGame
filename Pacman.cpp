#include "Pacman.hh"

TimeManager &timeManagerPacman = TimeManager::GetInstance();

Pacman::Pacman(){
	this->SetLife(3);
	this->SetX(13);
	this->SetY(23);
}

Pacman::~Pacman(){}

void Pacman::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
		std::cout << "+1 observer" << std::endl;
}

void Pacman::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
		std::cout << "-1 observer" << std::endl;
}

void Pacman::Update(){
	unsigned int value = timeManagerPacman.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

Event<int>* Pacman::getEvent(){
	return new Event<int>((int *)this->GetLife());
}

void Pacman::PacmanDied(){

	//if(GetLife() <= 0){
	//endGame();}
	//else{}->
	this->SetLife(this->GetLife() - 1);
	notify();
}


