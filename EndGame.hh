#ifndef ENDGAME_HH
#define ENDGAME_HH
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include <iostream>
#include <string>
#include "Pacman.hh"
#include <unistd.h>

#define MAX_NUMBER_OF_ITEMS_ENDGAME 1

class EndGame{
public:
	EndGame(float width, float height);
	~EndGame();

	void draw(sf::RenderWindow &Window);
	int GetPressedItem(){return selectedItemIndex;}
	int WindowEndGame(sf::RenderWindow &window, EndGame endGame, Pacman &pacman);
private:
	int selectedItemIndex;
    sf::Font font;
    sf::Text end[MAX_NUMBER_OF_ITEMS_ENDGAME];
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif //ENGAME_HH