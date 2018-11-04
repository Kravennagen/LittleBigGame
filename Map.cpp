#include "Map.hh"

Map::Map(float width, float height){

	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		//error
		std::cout << "font error" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("Time");
	text[0].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 1));

	/*text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString();
	text[1].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 2));
*/
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Blue);
	text[2].setString("Scores");
	text[2].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 3));
	
	/*text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString();
	text[3].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 4));
*/
	text[4].setFont(font);
	text[4].setFillColor(sf::Color::Blue);
	text[4].setString("FPS");
	text[4].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 5));
}

void Map::refresh(Event<int>* e){
	*e->getInfo();
	delete e;
}

Map::~Map(){}

void Map::draw(sf::RenderWindow &window, int score, int time, int fps){
	std::cout << "Dans draw" << std::endl;
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS_MAP; i++){
		window.draw(text[i]);
		text[1].setFont(font);
		text[1].setFillColor(sf::Color::White);
		text[1].setString(std::to_string(time));
		text[1].setPosition(sf::Vector2f(window.getSize().x /2, window.getSize().y / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 2));
		text[3].setFont(font);
		text[3].setFillColor(sf::Color::White);
		text[3].setString(std::to_string(score));
		text[3].setPosition(sf::Vector2f(window.getSize().x /2, window.getSize().y / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 4));
		text[5].setFont(font);
		text[5].setFillColor(sf::Color::Blue);
		text[5].setString(std::to_string(fps));
		text[5].setPosition(sf::Vector2f(window.getSize().x /2, window.getSize().y / (MAX_NUMBER_OF_ITEMS_MAP + 1) * 6));
	}
}


int Map::WindowMap(sf::RenderWindow &window, Map map, sf::Sound sound, Scores scores){
	static TimeManager& instance = TimeManager::GetInstance();
	static FPS& fps = FPS::GetInstanceFPS();
	instance.Start();
	while(window.isOpen()){
		instance.Update();
		float f = fps.getFps(instance);
		window.clear();
		sleep(1);
		map.draw(window, scores.GetScores(), instance.GetStartedTime(), f);
		window.display();
	}
}