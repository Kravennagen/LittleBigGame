#ifndef MAP_HH
#define MAP_HH

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include <string>
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Scores.hh"
#include "Observable.hpp"

#define MAX_NUMBER_OF_ITEMS_MAP 4

class Map: public Observer<int>{
public:
	Map(float width, float height, unsigned int time, double scores);
	~Map();

	void refresh(Event<int>* e);
	void draw(sf::RenderWindow &window);
	int WindowMap(sf::RenderWindow &window, Map map, sf::Sound sound, Scores scores);
private:
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_MAP];
};

#endif //MAP_HH