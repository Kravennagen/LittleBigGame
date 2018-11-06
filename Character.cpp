#include "Character.hh"

Character::Character() {

}

Character::~Character() {

}

int Character::GetX() const {
    return _x;
}

void Character::SetX(int _X) {
    Character::_x = _X;
}

int Character::GetY() const {
    return _y;
}

void Character::SetY(int _Y) {
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
