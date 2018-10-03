//
// Created by kraven on 03/10/18.
//

#ifndef SFML_MENU_HH
#define SFML_MENU_HH
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class Menu {

public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &Window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};


#endif //SFML_MENU_HH
