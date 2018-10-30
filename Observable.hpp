#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <list>
#include <algorithm>
#include <iterator>

#include "Observer.hpp"
#include "Event.hpp"

template <typename Object>

class Observable{
public:
	void addObserver(Observer<Object>* obs){
		this->_listObserver.push_back(obs);
	}

	void removeObserver(Observer<Object>* obs){
		ItListObs beginList = this->_listObserver.begin();
		ItListObs endList = this->_listObserver.end();

		ItListObs it = std::find(beginList, endList, obs);
		if(it!=endList){
			this->_listObserver.erase(it);
		}
	}

protected:
	virtual Event<Object>* getEvent() = 0;

	void notify(){
		ItListObs beginList = this->_listObserver.begin();
		ConstItListObs endList = this->_listObserver.end();

		for (ItListObs it = beginList; it != endList; ++it){
			(*it)->refresh(this->getEvent());
		}
	}

private:
	typedef Observer<Object>*					PtrObs;
	typedef std::list<PtrObs>					ListObs;
	typedef typename ListObs::iterator			ItListObs;
	typedef typename ListObs::const_iterator	ConstItListObs;
	ListObs 									_listObserver;
};

#endif // OBSERVABLE_HPP