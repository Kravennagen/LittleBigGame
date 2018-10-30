#ifndef OBSERVABLE_HH
#define OBSERVABLE_HH
#include <list>
#include <algorithm>
#include <iterator>
#include "Observer.hh"

template<typename Object>
class Object Observable {
public:
	Observable();
	virtual ~Observable();
	void addObserver(Observer<Object>* obs);
	void removeObserver(Observer<Object>* obs);
protected:
	virtual Event<Object>* getEvent() = 0;
	void notify();
private:
	typedef Observer<Object>* PtrObs;
	typedef std::list<PtrObs> ListObs;
	typedef typename ListObs::iterator ItListObs;
	typedef typename ListObs::const_iterator ConstItListObs;
	ListObs _listObserver;

};

#endif //OBSERVABLE_HH