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
#include "Observer.hpp"

using namespace std;

int main(){
    sf::RenderWindow window(sf::VideoMode(512, 512), "Pacman", sf::Style::Close);
    sf::SoundBuffer buffer;

    if(!buffer.loadFromFile("/home/kraven/Documents/cpp/LittleBigGame/pacman_beginning.wav")){
        //error
    }

    //Observer<int> observer;
    
    static TimeManager& instance = TimeManager::GetInstance();
    static FPS& fps = FPS::GetInstanceFPS();
    Scores scores;
    instance.Start();
    sf::Sound sound;

    //scores.addObserver(observer);

    sound.setBuffer(buffer);
    sound.stop();
    sound.setLoop(true);
    Menu menu(window.getSize().x, window.getSize().y);
    Options options(window.getSize().x, window.getSize().y);
    Map map(window.getSize().x, window.getSize().y, instance.GetStartedTime(), scores.GetScores());

    while(window.isOpen()){
        
        instance.Update();
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
                                    //static TimeManager& instance = TimeManager::GetInstance();
                                    //instance.Update() in the fps

                                    fps.getFps(instance);
                                    map.WindowMap(window, map, sound, scores);
                                    std::cout << "Play button has been pressed" << std::endl;
                                    break;
                                case 1:
                                    options.WindowOptions(window, options, sound);
                                    std::cout << "Options button has been pressed" << std::endl;
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
