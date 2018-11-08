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
}

void Pacman::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
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


	std::cout << "life pacman: " << this->GetLife() << std::endl;
	this->SetLife(this->GetLife() - 1);
	std::cout << "life pacman: " << this->GetLife() << std::endl;
	notify();
	if(this->GetLife() <= 0){
		std::cout << "game status : " << gameStatus.GetStatus() << std::endl;
		gameStatus.SetStatus(0);
		std::cout << "game status : " << gameStatus.GetStatus() << std::endl;
	}
}


