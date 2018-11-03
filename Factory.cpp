#include "Factory.hh"


Factory::Factory() {}

Factory::~Factory() {}

Character* Factory::Create(const std::string &Name) {

    if(Name == "Pinky"){
        //return ghost
        return new Pinky;
    }
    else if (Name == "Blinky"){
    	return new Blinky;
        //return else
    }
    else if (Name == "Inky"){
    	return new Inky;
    }
    else if (Name == "Clyde"){
    	return new Clyde;
    }
    else{
        return nullptr;
    }
}