#include "Options.hh"


Options::Options(float width, float height){
	if(!font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf")){
		//error
		std::cout << "font error" << std::endl;
	}

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("Sounds");
	text[0].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_OPTIONS + 1) * 1));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Goback");
	text[1].setPosition(sf::Vector2f(width /2, height / (MAX_NUMBER_OF_ITEMS_OPTIONS + 1) * 2));
	selectedItemIndex = 0;
}

Options::~Options(){}

void Options::draw(sf::RenderWindow &window){
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS_OPTIONS; i++){
		window.draw(text[i]);
	}
}

void Options::MoveUp(){
	if(selectedItemIndex -1 >= 0){
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex --;
		text[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

void Options::MoveDown(){
	if(selectedItemIndex +1 < MAX_NUMBER_OF_ITEMS_OPTIONS){
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex ++;
		text[selectedItemIndex].setFillColor(sf::Color::Blue);
	}
}

int Options::WindowOptions(sf::RenderWindow &window, Options options, sf::Sound sound){

	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::KeyReleased:
					switch(event.key.code){ 
						case sf::Keyboard::Up:
							options.MoveUp();
							break;
						case sf::Keyboard::Down:
							options.MoveDown();
							break;
						case sf::Keyboard::Return:
							switch(options.GetPressedItem()){
								case 0:
									std::cout << std::to_string(sound.getStatus()) << std::endl; 
									if(sound.getStatus() == sf::Sound::Status::Playing){
										std::cout << std::to_string(sound.getStatus()) << std::endl;
										//sound.setLoop(false);
										sound.stop();
									}else{
										std::cout << std::to_string(sound.getStatus()) << std::endl;
										sound.play();
										sound.setLoop(true);
									}
									break;
								case 1:
									//window.create(sf::VideoMode(800, 600), "pacman", sf::Style::Fullscreen);
									std::cout << "Go back button has been pressed" << std::endl;
									return 0;
									break;
							}
							break;
					}
					break;
			}
		}
		window.clear();
		options.draw(window);
		window.display();	
	}
	return 1;
}