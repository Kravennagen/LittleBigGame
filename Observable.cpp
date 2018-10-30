#include "Observable.hh"

Observable::Observable(){}
Observable::~Observable(){}

void Observable::addObserver(Observer<Object>* obs){
	this->_listObserver.push_back(obs);
}

void Observable::removeObserver(Observer<Object>* obs){
	ItListObs beginList = this->_listObserver.begin();
	ItListObs endList = this->_listObserver.end();

	ItListObs itObs = std::find(beginList, endList, obs);
	if(itObs != endList){
		this->_listObserver.erase(itObs);
	}
}

void Observable::getEvent(){}

void Observable::notify(){
	ItListObs beginList = this->_listObserver.begin();
	ConstItListObs endList = this->_listObserver.end();

	for(ItListObs it = beginList; it != endList; ++it){
		(*it)->refresh(this->getEvent());
	}
}
