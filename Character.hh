
#ifndef CHARACTER_HH
#define CHARACTER_HH


#include "AbstractEntity.hh"

class Character: AbstractEntity {

protected:
    Character();
    virtual ~Character();

public:
    int _x;
    int _y;
    int _life;
    int GetX() const;
    void SetX(int _X);
    int GetY() const;
    void SetY(int _Y);
    int GetLife() const;
    void SetLife(int _LIFE);
    void virtual Update();
    void virtual Draw();
};


#endif //CHARACTER_HH
