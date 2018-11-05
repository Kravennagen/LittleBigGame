#include "Pinky.hh"

TimeManager &timeManagerPinky = TimeManager::GetInstance();

Pinky::Pinky(){
	this->SetLife(1);
	std::cout << "life pinky" << this->GetLife() << std::endl;
	this->SetX(12);
	this->SetY(14);
	std::cout << "X pinky" << this->GetX() << std::endl;
	std::cout << "Y pinky" << this->GetY() << std::endl;
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


//for pacman 
void Pinky::CheckPosition(int _x, int _y, int level[31][28]){
	std::cout << "level 0" << level[0][0] << std::endl;
	if(level[_x][_y] != 0){
		this->SetX(_x);
		this->SetY(_y);
	}else{
		this->SetX(GetX());
		this->SetY(GetY());
	}
	std::cout << "X pinky" << this->GetX() << std::endl;
	std::cout << "Y pinky" << this->GetY() << std::endl;
}