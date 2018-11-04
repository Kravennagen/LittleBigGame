#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include "Event.hpp"

template <typename Object>

class Observer {
public:
	Observer(){};
	virtual ~Observer(){};
	virtual void refresh(Event<Object>* e) = 0;
};

#endif // OBSERVER_HPP