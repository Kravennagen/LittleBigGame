#include "EndGame.hh"

EndGame::EndGame(float width, float height){
	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		std::cout << "Font error End Game" << std::endl; 
	}

	end[0].setFont(font);
	end[0].setFillColor(sf::Color::Red);
	end[0].setString("Exit Game");
	end[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS_ENDGAME + 1) * 1));

	selectedItemIndex = 0;
	
}

EndGame::~EndGame(){}

void EndGame::draw(sf::RenderWindow &window){
	for (int i=0; i < MAX_NUMBER_OF_ITEMS_ENDGAME; i++){
		window.draw(end[i]);
	}
}

int EndGame::WindowEndGame(sf::RenderWindow &window, EndGame endGame, Pacman &pacman){

	while(window.isOpen()){
		
		if (!texture.loadFromFile("win.jpg") || !texture.loadFromFile("gameover.jpg"))
		{
			std::cout << "Texture EndGame Error" << std::endl;
		}
		
		if(pacman.GetLife() <= 0){
			texture.loadFromFile("gameover.jpg");
		}else{
			texture.loadFromFile("win.jpg");
		}

		sprite.setTexture(texture);
		sprite.setOrigin(0, 0);
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::KeyReleased:
				switch(event.key.code){
					case sf::Keyboard::Return:
					switch(endGame.GetPressedItem()){
						case 0:
						window.close();
						break;
					}
					break;
				}
				break;
			}
		}
		window.clear();
		window.draw(sprite);
		endGame.draw(window);
		window.display();
	}
}
