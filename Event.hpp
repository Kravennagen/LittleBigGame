#ifndef Event_HPP
#define Event_HPP

template <typename Object>

class Event{
public:
	Event(Object* obj){
		this->_obj = obj;
	}

	~Event(){
		delete this->_obj;
	}

	Object* getInfo(){
		return this->_obj;
	}

private:
	Object* _obj;
};

#endif //EVENT_HPP