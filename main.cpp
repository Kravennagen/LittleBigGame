//
// Created by kraven on 03/10/18.
//

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Menu.hh"
#include "Options.hh"
#include "SFML/Audio.hpp"
#include "TimeManager.hh"
#include "FPS.hh"
#include "Scores.hh"
#include "Map.hh"
#include "Factory.hh"
#include "Pacman.hh"
#include "EndGame.hh"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 562), "Pacman", sf::Style::Close);
    sf::SoundBuffer buffer;

    if(!buffer.loadFromFile("/home/kraven/Documents/cpp/LittleBigGame/pacman_beginning.wav")){
        //error
        std::cout << "Sound not found" << std::endl;
    }
    
    
    Factory factory;
    Scores scores;
    
    sf::Sound sound;
    factory.Create("Pinky");
    factory.Create("Blinky");
    factory.Create("Clyde");
    factory.Create("Inky");

    sound.setBuffer(buffer);
    sound.stop();
    sound.setLoop(true);
    Menu menu(window.getSize().x, window.getSize().y);
    Options options(window.getSize().x, window.getSize().y);
    Map map(window.getSize().x, window.getSize().y);
    EndGame endGame(window.getSize().x, window.getSize().y);
    

    while(window.isOpen()){
        sf::Event event;
        while( window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch(event.key.code){
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch(menu.GetPressedItem()){
                                case 0:
                                    map.WindowMap(window, map, scores);
            
                                    break;
                                case 1:
                                    options.WindowOptions(window, options, sound);
                                    
                                    break;
                                case 2:
                                    window.close();
                                    break;
                            }
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        window.clear();
        menu.draw(window);
        window.display();
    }
}
