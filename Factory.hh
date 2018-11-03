#ifndef FACTORY_HH
#define FACTORY_HH


#include <string>
#include "Character.hh"
#include "Blinky.hh"
#include "Pinky.hh"
#include "Inky.hh"
#include "Clyde.hh"

class Factory {
public:
    Factory();
    ~Factory();
    Character* Create(const std::string&);

};


#endif //FACTORY_HH