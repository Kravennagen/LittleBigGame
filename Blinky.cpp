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
}

void Blinky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Blinky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}


void Blinky::move(){
	point s, e( 26, 1 );

	if(asBlinky.search(s, e, mBlinky)){
		std::list<point> path;
		int c = asBlinky.path( path );
		int j = 0;
		
		
		for(std::list<point>::iterator i = path.begin(); i!= path.end(); i++){
			if(j == 1){
				std::cout << "(" << ( *i ).x << ", " << ( *i ).y << ") " << std::endl;
			}
			j++;
		}
	}
}
