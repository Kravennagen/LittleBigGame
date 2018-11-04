#include "Map.hh"

Map::Map(float width, float height){

	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		//error
		std::cout << "font error" << std::endl;
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

	const int level[31][28] =
	{

		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
		{0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
		{0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
		{0,3,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,3,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
		{0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
		{0,2,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,2,0},
		{0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
		{0,0,0,0,0,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,0,0,0,0,0},
		{1,1,1,1,1,0,2,0,0,0,0,0,1,0,0,1,0,0,0,0,0,2,0,1,1,1,1,1},
		{1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
		{1,1,1,1,1,0,2,0,0,1,0,0,0,7,7,0,0,0,1,0,0,2,0,1,1,1,1,1},
		{0,0,0,0,0,0,2,0,0,1,0,1,1,1,1,1,1,0,1,0,0,2,0,0,0,0,0,0},
		{6,1,1,1,1,1,2,1,1,1,0,1,1,1,1,1,1,0,1,1,1,2,1,1,1,1,1,6},
		{0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
		{1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
		{1,1,1,1,1,0,2,0,0,1,1,1,1,1,1,1,1,1,1,0,0,2,0,1,1,1,1,1},
		{1,1,1,1,1,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,1,1,1,1,1},
		{0,0,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,1,0,0,2,0,0,0,0,0,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0},
		{0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
		{0,2,0,0,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,0,0,2,0},
		{0,3,2,2,0,0,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,0,0,2,2,3,0},
		{0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
		{0,0,0,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,2,0,0,2,0,0,0},
		{0,2,2,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,2,2,2,2,2,0},
		{0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
		{0,2,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,0},
		{0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

    // on crée la tilemap avec le niveau précédemment défini

	if (!texture.loadFromFile("map.png"))
	{
    	// Erreur...
	}

	if (!tileMap.load("tile_gum.png", sf::Vector2u(16, 16), level, 28, 31))
    //error


	texture.loadFromFile("map.png");

  // Create a sprite

	sprite.setTexture(texture);
	sprite.setOrigin(0,-50);
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


int Map::WindowMap(sf::RenderWindow &window, Map map, sf::Sound sound, Scores scores){
	static TimeManager& instance = TimeManager::GetInstance();
	static FPS& fps = FPS::GetInstanceFPS();
	instance.Start();
	while(window.isOpen()){
		instance.Update();
		float f = fps.getFps(instance);
		window.clear();
		
		window.draw(sprite);
		window.draw(tileMap);
		sleep(1);
		map.drawText(window, scores.GetScores(), instance.GetStartedTime(), f);
		window.display();
	}
}