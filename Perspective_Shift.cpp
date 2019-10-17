//
//  main.cpp
//  building_Shift
//
//  Created by Gabrielle Madden on 2019-01-17.
//  Copyright © 2019 Gabrielle Madden. All rights reserved.
//

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(400, 400), "Perspective Shift");
    Texture baseT, l1T, l2T, l3T, l4T, l5T;
    if (!baseT.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/base.png")) return EXIT_FAILURE;
    if (!l1T.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/layer1.png")) return EXIT_FAILURE;
    if (!l2T.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/layer2.png")) return EXIT_FAILURE;
    if (!l3T.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/layer3.png")) return EXIT_FAILURE;
    if (!l4T.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/layer4.png")) return EXIT_FAILURE;
    if (!l5T.loadFromFile("/Users/gabriellemadden/Coding projects/buildingshift/resources/layer5.png")) return EXIT_FAILURE;
    
    Sprite base(baseT), l1(l1T), l2(l2T), l3(l3T), l4(l4T), l5(l5T);
    Sprite l[5];
    {
        l[0] = l1;
        l[1] = l2;
        l[2] = l3;
        l[3] = l4;
        l[4] = l5;
    }
    base.setPosition(-50, -50);
    l[0].setOrigin(41, 31);
    l[0].setPosition(200, 200);
    l[1].setOrigin(42, 32);
    l[1].setPosition(200, 200);
    l[2].setOrigin(43, 33);
    l[2].setPosition(200, 200);
    l[3].setOrigin(44, 34);
    l[3].setPosition(200, 200);
    l[4].setOrigin(45, 35);
    l[4].setPosition(200, 200);

    
    window.draw(base);
    for (int i = 0; i < 5; i++)
        window.draw(l[i]);

    
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Left){
                        base.setPosition(base.getPosition().x - 5, base.getPosition().y);
                        for (int i = 0; i<5; i++){
                            l[i].setPosition(l[i].getPosition().x - (6+i), l[i].getPosition().y);
                        }
                    }
                    else if (event.key.code == Keyboard::Right){
                        base.setPosition(base.getPosition().x + 5, base.getPosition().y);
                        for (int i = 0; i<5; i++){
                            l[i].setPosition(l[i].getPosition().x + (6+i), l[i].getPosition().y);
                        }
                    }
                    else if (event.key.code == Keyboard::Up){
                        base.setPosition(base.getPosition().x, base.getPosition().y - 5);
                        for (int i = 0; i<5; i++){
                            l[i].setPosition(l[i].getPosition().x, l[i].getPosition().y - (6+i));
                        }
                    }
                    else if (event.key.code == Keyboard::Down){
                        base.setPosition(base.getPosition().x, base.getPosition().y + 5);
                        for (int i = 0; i<5; i++){
                            l[i].setPosition(l[i].getPosition().x, l[i].getPosition().y + (6+i));
                        }
                    }
            }
            window.draw(base);
            for (int i = 0; i < 5; i++)
                window.draw(l[i]);
            window.display();

        }
    }
}
