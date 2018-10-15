#include "Character.hh"

Character::Character() {

}

Character::~Character() {

}

double Character::GetX() const {
    return _x;
}

void Character::SetX(double _X) {
    Character::_x = _X;
}

double Character::GetY() const {
    return _y;
}

void Character::SetY(double _Y) {
    Character::_y = _Y;
}

int Character::GetLife() const {
    return _life;
}

void Character::SetLife(int __LIFE) {
    Character::_life = __LIFE;
}

void Character::Update() {
}

void Character::Draw() {

}