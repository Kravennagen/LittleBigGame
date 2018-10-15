#ifndef ABSTRACTENTITY_HH
#define ABSTRACTENTITY_HH

class AbstractEntity
{

protected:
    //constructeur
    AbstractEntity();
    //destructeur
    virtual ~AbstractEntity();
public:
    virtual void Update() = 0;
    virtual void Draw() = 0 ;

};


#endif //ABSTRACTENTITY_HH