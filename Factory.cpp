#include "Factory.hh"

Factory::Factory() {}

Factory::~Factory() {}

Character* Factory::Create(const std::string &Name) {

    if(Name == "Ghost"){
        //return ghost
    }
    else if (Name == "else"){
        //return else
    }
    else{
        return nullptr;
    }
}