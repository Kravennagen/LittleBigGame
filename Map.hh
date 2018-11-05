#ifndef MAP_HH
#define MAP_HH

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include <string>
#include <iostream>
#include "SFML/Audio.hpp"
#include "Scores.hh"
#include "Observable.hpp"
#include "Observer.hpp"
#include "TimeManager.hh"
#include "FPS.hh"
#include <unistd.h>
#include "TileMap.hpp"

#define MAX_NUMBER_OF_ITEMS_MAP 6


class Map: public Observer<int>{
public:
	Map(float width, float height);
	virtual ~Map();

	virtual void refresh(Event<int>* e) override;
	void drawText(sf::RenderWindow &window, int score, int time, int fps);
	int WindowMap(sf::RenderWindow &window, Map map, sf::Sound sound, Scores scores);

protected:
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_MAP];
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Event event;
	TileMap tileMap;
};

#endif //MAP_HH