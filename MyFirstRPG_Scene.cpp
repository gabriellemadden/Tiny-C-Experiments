#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    int screenWidth = 400, screenHeight = 300;
    RenderWindow window(VideoMode(screenWidth, screenHeight), "CozyTown");
    
    Texture mapUpTexture;
    Texture mapDownTexture;
    Texture characterTexture;
    if (!mapUpTexture.loadFromFile("/Users/gabriellemadden/Coding projects/myfirst_RPGscene/resources/map-upperlayer.png"))
        return EXIT_FAILURE;
    if (!mapDownTexture.loadFromFile("/Users/gabriellemadden/Coding projects/myfirst_RPGscene/resources/map-lowerlayer.png"))
        return EXIT_FAILURE;
    if (!characterTexture.loadFromFile("/Users/gabriellemadden/Coding projects/myfirst_RPGscene/resources/character-sprite.png")) return EXIT_FAILURE;
    
    Sprite mapUp(mapUpTexture);
    mapUp.setPosition(-475, 0);
    
    Sprite mapDown(mapDownTexture);
    mapDown.setPosition(-475, 0);
    
    Sprite character(characterTexture);
    character.setPosition(175, 5);
    
    window.draw(mapDown);
    window.draw(character);
    window.draw(mapUp);
    
    bool charCentredVert = false, charCentredHor = false;
    
    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            charCentredVert = false;
            charCentredHor = false;
            if (character.getPosition().x == 175) charCentredHor = true;
            if (character.getPosition().y == 125) charCentredVert = true;
            switch (event.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Right){
                        if (!charCentredHor && character.getPosition().x < 350) {
                            character.setPosition(character.getPosition().x + 10, character.getPosition().y);
                        }
                        else if (!(mapDown.getPosition().x <= -990 + screenWidth)){
                            mapUp.setPosition((mapUp.getPosition().x - 10), (mapUp.getPosition().y));
                            mapDown.setPosition((mapDown.getPosition().x - 10), (mapDown.getPosition().y));
                        }
                        else if (character.getPosition().x < 350){
                            character.setPosition(character.getPosition().x + 10, character.getPosition().y);
                        }
                    }
                    if (event.key.code == Keyboard::Left){
                        if (!charCentredHor && character.getPosition().x > 10) {
                            character.setPosition(character.getPosition().x - 10, character.getPosition().y);
                        }
                        else if (mapDown.getPosition().x <= -10){
                            mapDown.setPosition((mapDown.getPosition().x + 10), (mapDown.getPosition().y));
                            mapUp.setPosition((mapUp.getPosition().x + 10), (mapUp.getPosition().y));
                        }
                        else if (character.getPosition().x > 10){
                            character.setPosition(character.getPosition().x - 10, character.getPosition().y);
                        }
                    }
                    if (event.key.code == Keyboard::Down){
                        if (!charCentredVert && character.getPosition().y < 245){
                            character.setPosition(character.getPosition().x, character.getPosition().y + 10);
                        }
                        else if (!(mapDown.getPosition().y <= -990 + screenHeight)){
                            mapDown.setPosition((mapDown.getPosition().x), (mapDown.getPosition().y - 10));
                            mapUp.setPosition((mapUp.getPosition().x), (mapUp.getPosition().y - 10));
                        }
                        else if (character.getPosition().y < 245){
                            character.setPosition(character.getPosition().x, character.getPosition().y + 10);
                        }
                    }
                    if (event.key.code == Keyboard::Up){
                        if (!charCentredVert && character.getPosition().y > 5){
                            character.setPosition(character.getPosition().x, character.getPosition().y - 10);
                        }
                        else if (mapDown.getPosition().y <= -10){
                            mapDown.setPosition((mapDown.getPosition().x), (mapDown.getPosition().y + 10));
                            mapUp.setPosition((mapUp.getPosition().x), (mapUp.getPosition().y + 10));
                        }
                        else if (character.getPosition().y > 5){
                            character.setPosition(character.getPosition().x, character.getPosition().y - 10);
                        }
                    }
            }
            window.draw(mapDown);
            window.draw(character);
            window.draw(mapUp);
            window.display();
        }
    }
    
}
