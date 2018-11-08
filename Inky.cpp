#include "Inky.hh"

TimeManager &timeManagerInky = TimeManager::GetInstance();

Inky::Inky(){
	this->SetLife(1);
	this->SetX(13);
	this->SetY(15);
}

Inky::~Inky(){}

void Inky::Update(){
	unsigned int value = timeManagerInky.GetElapsedTime();
    this->SetX(this->GetX()+(value/200.0));
    this->SetY(this->GetY()+(value/200.0));
}

void Inky::addObserver(Observer<int>* obs){
		Observable<int>::addObserver(obs);
}

void Inky::removeObserver(Observer<int>* obs){
		Observable<int>::removeObserver(obs);
}

Event<int>* Inky::getEvent(){
	return new Event<int>((int *)this->GetLife());
}

void Inky::move(Pacman &pacman){
	aStar asInky;
	point s(this->GetX(), this->GetY()), e(pacman.GetX(), pacman.GetY());

	if(asInky.search(s, e, mInky)){
		std::list<point> path;
		int c = asInky.path( path );
		int j = 0;
		
		for(std::list<point>::iterator i = path.begin(); i!= path.end(); i++){
			if(j == 1){
				//std::cout << "(" << ( *i ).x << ", " << ( *i ).y << ") " << std::endl;
				this->SetX(( *i ).x);
				this->SetY(( *i ).y);				
			}
			j++;
		}
	}
}