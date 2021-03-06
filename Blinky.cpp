#include "Blinky.hh"

TimeManager &timeManagerBlinky = TimeManager::GetInstance();

Blinky::Blinky(){
	this->SetLife(1);
	this->SetX(13);
	this->SetY(12);
	
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


void Blinky::move(Pacman &pacman){
	aStar asBlinky;
	point s(this->GetX(), this->GetY()), e(pacman.GetX(), pacman.GetY());
	if( GetX()+1 == pacman.GetX() && GetY() == pacman.GetY() ||  
        GetX()-1 == pacman.GetX() && GetY() == pacman.GetY() || 
         GetX() == pacman.GetX() && GetY()+1 == pacman.GetY() ||
        GetX() == pacman.GetX() && GetY()-1 == pacman.GetY()){ 
        SetX(pacman.GetX());
        SetY(pacman.GetY());
        }
        else{

	if(asBlinky.search(s, e, mBlinky)){
		std::list<point> path;
		int c = asBlinky.path( path );
		int j = 0;
		
		
		for(std::list<point>::iterator i = path.begin(); i!= path.end(); i++){
			if(j == 1){
				
				this->SetX(( *i ).x);
				this->SetY(( *i ).y);
			}
			j++;
		}
	}
}
}
