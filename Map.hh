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
#include "Pinky.hh"
#include "Clyde.hh"
#include "Inky.hh"
#include "Blinky.hh"
#include "LevelMap.hh"

#define MAX_NUMBER_OF_ITEMS_MAP 6


class Map: public Observer<int>{
public:
	Map(float width, float height);
	virtual ~Map();
	virtual void refresh(Event<int>* e) override;
	void drawText(sf::RenderWindow &window, int score, int time, int fps);
	int WindowMap(sf::RenderWindow &window, Map map, Scores scores);
	
	
protected:
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_MAP];
	sf::Event event;
};

#endif //MAP_HH