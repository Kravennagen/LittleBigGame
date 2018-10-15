
#ifndef CHARACTER_HH
#define CHARACTER_HH


#include "AbstractEntity.hh"

class Character: AbstractEntity {

protected:
    Character();
    virtual ~Character();

public:
    double _x;
    double _y;
    int _life;
    double GetX() const;
    void SetX(double _X);
    double GetY() const;
    void SetY(double _Y);
    int GetLife() const;
    void SetLife(int _LIFE);
    void virtual Update();
    void virtual Draw();
};


#endif //CHARACTER_HH