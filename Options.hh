#ifndef SFML_OPTIONS_HH
#define SFML_OPTIONS_HH
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include <string>
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS_OPTIONS 2

class Options {
public:
	Options(float width, float height);
	~Options();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem(){return selectedItemIndex;}
	int WindowOptions(sf::RenderWindow &window, Options options, sf::Sound sound);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_OPTIONS];
};

#endif //SFML_OPTIONS_HH
