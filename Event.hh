#ifndef EVENT_HH
#define EVENT_HH

template <typename Object>

class Event {
public:
	Event(Object* obj);
	~Event();
	Object* getInfo();
private:
	Object* _obj;
};

#endif //EVENT_HH