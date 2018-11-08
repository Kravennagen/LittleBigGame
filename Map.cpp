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
	int level[31][28] =
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
	if (!texture.loadFromFile("map.png"))
	{
		std::cout << "Texture Error" << std::endl;
	}

	if (!tileMap.load("tile_gum.png", sf::Vector2u(16, 16), level, 28, 31))
		std::cout << "TileMap Error" << std::endl;


	texture.loadFromFile("map.png");
	sprite.setTexture(texture);
	sprite.setOrigin(0,-50);

	w = 31;
	h = 28;
	m[w][h];
	static TimeManager& instance = TimeManager::GetInstance();
	static FPS& fps = FPS::GetInstanceFPS();
	Balls balls;
	Pinky pinky;
	Blinky blinky;
	Inky inky;
	Clyde clyde;
	Pacman pacman;
	instance.Start();
	int i;
	while(window.isOpen()){

		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed)
				window.close();
			switch(event.type){
				case sf::Event::KeyReleased:
					pinky.move(pacman);
					blinky.move(pacman);

					inky.move(pacman);
					clyde.move(pacman);
				switch(event.key.code)
				{

					case sf::Keyboard::Down:
					
					if(level[pacman.GetY()+1][pacman.GetX()] != 0)
						pacman.SetY(pacman.GetY()+1);
					
					balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
					level[pacman.GetY()][pacman.GetX()] = 1;
					
					
					/*if(level[pacman.GetY()][pacman.GetX()] == 3){
						for(i = instance.GetStartedTime(); i < instance.GetStartedTime() + 10; i++){
							if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY()){
								pinky.SetLife(pinky.GetLife() - 1);
								pinky.SetX(14);
								pinky.SetY(14);
							}
							if(inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY()){
								inky.SetLife(inky.GetLife() - 1);
								inky.SetX(14);
								inky.SetY(15);
							}
							if(clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY()){
								clyde.SetLife(clyde.GetLife() - 1);
								clyde.SetX(13);
								clyde.SetY(13);
							}
							if(blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
								blinky.SetLife(blinky.GetLife() - 1);
								blinky.SetX(13);
								blinky.SetY(12);
							}
						}
						
					}else{*/
						if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY() || inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY() || clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY() || blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
							pacman.PacmanDied();
							pacman.SetX(13);
							pacman.SetY(23);
							if(pacman.GetLife() <= 0){

								gameStatus.SetStatus(0);
							}
						}
					//}

					break;
					case sf::Keyboard::Up:
					if(level[pacman.GetY()-1][pacman.GetX()] != 0)
						pacman.SetY(pacman.GetY()-1);
					balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
					level[pacman.GetY()][pacman.GetX()] = 1;
							
					
					if (!tilePacman.move("pacman.png", sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
						return -1;
					/*if(level[pacman.GetY()][pacman.GetX()] == 3){
						for(i = instance.GetStartedTime(); i < instance.GetStartedTime() + 10; i++){
							if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY()){
								pinky.SetLife(pinky.GetLife() - 1);
								pinky.SetX(144);
								pinky.SetY(14);
							}
							if(inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY()){
								inky.SetLife(inky.GetLife() - 1);
								inky.SetX(14);
								inky.SetY(15);
							}
							if(clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY()){
								clyde.SetLife(clyde.GetLife() - 1);
								clyde.SetX(13);
								clyde.SetY(13);
							}
							if(blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
								blinky.SetLife(blinky.GetLife() - 1);
								blinky.SetX(13);
								blinky.SetY(12);
							}
						}
						
					}else{*/
						if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY() || inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY() || clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY() || blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
							pacman.PacmanDied();
							pacman.SetX(13);
							pacman.SetY(23);
							if(pacman.GetLife() <= 0){

								gameStatus.SetStatus(0);
							}
						}
					//}				
					break;
					case sf::Keyboard::Left:
					if(level[pacman.GetY()][pacman.GetX()-1] != 0)
						pacman.SetX(pacman.GetX()-1);
					balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
					level[pacman.GetY()][pacman.GetX()] = 1;
						
					
					if (!tilePacman.move("pacman.png", sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
						return -1;
					/*if(level[pacman.GetY()][pacman.GetX()] == 3){
						for(i = instance.GetStartedTime(); i < instance.GetStartedTime() + 10; i++){
							if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY()){
								pinky.SetLife(pinky.GetLife() - 1);
								pinky.SetX(144);
								pinky.SetY(14);
							}
							if(inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY()){
								inky.SetLife(inky.GetLife() - 1);
								inky.SetX(14);
								inky.SetY(15);
							}
							if(clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY()){
								clyde.SetLife(clyde.GetLife() - 1);
								clyde.SetX(13);
								clyde.SetY(13);
							}
							if(blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
								blinky.SetLife(blinky.GetLife() - 1);
								blinky.SetX(13);
								blinky.SetY(12);
							}
						}
						
					}else{*/
						if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY() || inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY() || clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY() || blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
							pacman.PacmanDied();
							pacman.SetX(13);
							pacman.SetY(23);
							if(pacman.GetLife() <= 0){

								gameStatus.SetStatus(0);
							}
						}
					//}					
					break;
					case sf::Keyboard::Right:
					if(level[pacman.GetY()][pacman.GetX()+1] != 0)
						pacman.SetX(pacman.GetX()+1);
					balls.BallsWasEat(level[pacman.GetY()][pacman.GetX()], scores, gameStatus);
					level[pacman.GetY()][pacman.GetX()] = 1;
							
					
					if (!tilePacman.move("pacman.png", sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
						return -1;
					/*if(level[pacman.GetY()][pacman.GetX()] == 3){
						for(i = instance.GetStartedTime(); i < instance.GetStartedTime() + 10; i++){
							if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY()){
								pinky.SetLife(pinky.GetLife() - 1);
								pinky.SetX(144);
								pinky.SetY(14);
							}
							if(inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY()){
								inky.SetLife(inky.GetLife() - 1);
								inky.SetX(14);
								inky.SetY(15);
							}
							if(clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY()){
								clyde.SetLife(clyde.GetLife() - 1);
								clyde.SetX(13);
								clyde.SetY(13);
							}
							if(blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
								blinky.SetLife(blinky.GetLife() - 1);
								blinky.SetX(13);
								blinky.SetY(12);
							}
						}
						
					}else{*/
						if(pinky.GetX() == pacman.GetX() && pinky.GetY() == pacman.GetY() || inky.GetX() == pacman.GetX() && inky.GetY() == pacman.GetY() || clyde.GetX() == pacman.GetX() && clyde.GetY() == pacman.GetY() || blinky.GetX() == pacman.GetX() && blinky.GetY() == pacman.GetY()){
							pacman.PacmanDied();
							pacman.SetX(13);
							pacman.SetY(23);
							if(pacman.GetLife() <= 0){

								gameStatus.SetStatus(0);
							}
						}
					//}
					break;
				}
				break;
				
			}


		}
		
		if(gameStatus.GetStatus() == 0){
			EndGame endGame(window.getSize().x, window.getSize().y);
			endGame.WindowEndGame(window, endGame, pacman);
		}
		instance.Update();
		float f = fps.getFps(instance);
		if (!tileMap.load("tile_gum.png", sf::Vector2u(16, 16), level, 28, 31))
			std::cout << "TileMap Error" << std::endl;
if (!tilePinky.moveGhost("pinky.png", sf::Vector2u(16, 16), pinky.GetX(), pinky.GetY()))
						return -1;
					if (!tileBlinky.moveGhost("blinky.png", sf::Vector2u(16, 16), blinky.GetX(), blinky.GetY()))
						return -1;
					if (!tileInky.moveGhost("inky.png", sf::Vector2u(16, 16), inky.GetX(), inky.GetY()))
						return -1;
					if (!tileClyde.moveGhost("clyde.png", sf::Vector2u(16, 16), clyde.GetX(), clyde.GetY()))
						return -1;
					if (!tilePacman.move("pacman.png", sf::Vector2u(16, 16), pacman.GetX(), pacman.GetY()))
						return -1;
		window.clear();
		window.draw(sprite);
		window.draw(tilePacman);
		window.draw(tilePinky);
		window.draw(tileClyde);
		window.draw(tileInky);
		window.draw(tileBlinky);
		window.draw(tileMap);//balls
		//sleep(1);
		map.drawText(window, scores.GetScores(), instance.GetStartedTime(), f);
		window.display();
	}
}
