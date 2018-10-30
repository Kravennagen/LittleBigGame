#ifndef OBSERVER_HH
#define OBSERVER_HH
#include "Event.hh"

template <typename Object>

class Object Observer {
public:
	Observer();
	virtual ~Observer();
	virtual void refresh(Event<Object>* e) = 0;
};

#endif //OBSERVER_HH