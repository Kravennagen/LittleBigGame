#include "Clyde.hh"

TimeManager &timeManagerClyde = TimeManager::GetInstance();

Clyde::Clyde(){
	this->SetLife(1);
	this->SetX(13);
	this->SetY(13);
}

Clyde::~Clyde(){}

void Clyde::Update(){
	unsigned int value = timeManagerClyde.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Clyde::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Clyde::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Clyde::getEvent(){
	return new Event<int>((int *)this->GetLife());
}

void Clyde::move(Pacman &pacman){
	aStar asClyde;
	point s(this->GetX(), this->GetY()), e(pacman.GetX(), pacman.GetY());
	if( GetX()+1 == pacman.GetX() && GetY() == pacman.GetY() ||  
        GetX()-1 == pacman.GetX() && GetY() == pacman.GetY() || 
         GetX() == pacman.GetX() && GetY()+1 == pacman.GetY() ||
        GetX() == pacman.GetX() && GetY()-1 == pacman.GetY()){ 
        SetX(pacman.GetX());
        SetY(pacman.GetY());
        }
        else{
	if(asClyde.search(s, e, mClyde)){
		std::list<point> path;
		int c = asClyde.path( path );
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
