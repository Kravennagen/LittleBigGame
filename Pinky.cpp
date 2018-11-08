#include "Pinky.hh"

TimeManager &timeManagerPinky = TimeManager::GetInstance();

Pinky::Pinky(){
	this->SetLife(1);
	this->SetX(1);
	this->SetY(1);
}

Pinky::~Pinky(){}

void Pinky::Update(){
	unsigned int value = timeManagerPinky.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Pinky::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Pinky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Pinky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}


void Pinky::CheckPosition(int _x, int _y, int level[31][28]){
	
	if(level[_x][_y] != 0){
		this->SetX(_x);
		this->SetY(_y);
	}else{
		this->SetX(GetX());
		this->SetY(GetY());
	}
	
}

void Pinky::move(Pacman &pacman){
	point s(this->GetX(), this->GetY()), e( pacman.GetX(), pacman.GetY());

	if(asPinky.search(s, e, mPinky)){
		std::list<point> path;

		int c = asPinky.path( path );
		int j = 0;
		
		for(std::list<point>::iterator i = path.begin(); i!= path.end(); i++){
			if(j == 1){
				std::cout << "pinky x: " << this->GetX() << "pinky y: " << this->GetY() << std::endl;
				std::cout << "(" << ( *i ).x << ", " << ( *i ).y << ") " << std::endl;
				this->SetX(( *i ).x);
				this->SetY(( *i ).y);
			}
			j++;
		}
	}
}