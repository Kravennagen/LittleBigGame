#include "Map.hh"

Map::Map(float width, float height, unsigned int time, double scores){
	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		//error
		std::cout << "font error" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("Time");
	text[0].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 1));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString(std::to_string(time));
	text[1].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 2));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Blue);
	text[2].setString("Scores");
	text[2].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 3));
	
	text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString(std::to_string(scores));
	text[3].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 4));

}

void Map::refresh(Event<int>* e){
	*e->getInfo();
	delete e;
}

Map::~Map(){}

void Map::draw(sf::RenderWindow &window){
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS_MAP; i++){
		window.draw(text[i]);
	}
}

int Map::WindowMap(sf::RenderWindow &window, Map map, sf::Sound sound, Scores scores){
	while(window.isOpen()){
		sf::Event event;
		window.clear();
		map.draw(window);
		window.display();
	}
}