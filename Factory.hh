#ifndef FACTORY_HH
#define FACTORY_HH


#include <string>
#include "Character.hh"

class Factory {
public:
    Factory();
    ~Factory();
    Character* Create(const std::string&);

};


#endif //FACTORY_HH