#include "Map.hh"


Map::Map(float width, float height){

	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		std::cout << "Font error Map" << std::endl;
	}
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("Time");
	text[0].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 1, 0));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Blue);
	text[2].setString("Score");
	text[2].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 3, 0));

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::Blue);
	text[4].setString("FPS");
	text[4].setPosition(sf::Vector2f(width /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 5, 0));

	LevelMap();
	
}

void Map::refresh(Event<int>* e){
	*e->getInfo();
	delete e;
}

Map::~Map(){}

void Map::drawText(sf::RenderWindow &window, int score, int time, int fps){
	
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS_MAP; i++){
		window.draw(text[i]);
		text[1].setFont(font);
		text[1].setFillColor(sf::Color::White);
		text[1].setString(std::to_string(time));
		text[1].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 2, 0));

		text[3].setFont(font);
		text[3].setFillColor(sf::Color::White);
		text[3].setString(std::to_string(score));
		text[3].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP) * 4, 0));

		text[5].setFont(font);
		text[5].setFillColor(sf::Color::White);
		text[5].setString(std::to_string(fps));
		text[5].setPosition(sf::Vector2f(window.getSize().x /(MAX_NUMBER_OF_ITEMS_MAP + 1) * 6, 0));
	}
}


int Map::WindowMap(sf::RenderWindow &window, Map map, Scores scores){
	static TimeManager& instance = TimeManager::GetInstance();
	static FPS& fps = FPS::GetInstanceFPS();
	Pinky pinky;
	Blinky blinky;
	Inky inky;
	Clyde clyde;
	LevelMap levelMap;
		
	instance.Start();
	while(window.isOpen()){
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		instance.Update();
		float f = fps.getFps(instance);

		window.clear();
		window.draw(levelMap.sprite);
		window.draw(levelMap.tileMap);//balls
		sleep(1);
		map.drawText(window, scores.GetScores(), instance.GetStartedTime(), f);
		window.display();
	}
}