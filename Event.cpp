#include "Event.hh"

Event::Event(Object* obj) {
	this->_obj = obj;
}

Event::~Event() {
	delete this->_obj;
}

Event::getInfo() {
	return this->_obj;
}