#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "src/SpriteSheet.h"
#include "src/MapManager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Works!");

    SpriteSheet sheet(128);
    if (!sheet.loadTextureFromFile("tilesheet_complete_2X.png")) {
        std::cout << "Error loading tilesheet" << std::endl;
        return -1;
    }

    MapManager mapManager(sheet);
    if (!mapManager.loadFromFile("map_file.gmap")) {
        std::cout << "Error loading map" << std::endl;
        return -1;
    }

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                // Move camera up
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                    sf::View view = window.getView();
                    view.move(0, -128);
                    window.setView(view);
                }

                // Move camera down
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    sf::View view = window.getView();
                    view.move(0, 128);
                    window.setView(view);
                }

                // Move camera left
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    sf::View view = window.getView();
                    view.move(-128, 0);
                    window.setView(view);
                }

                // Move camera right
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    sf::View view = window.getView();
                    view.move(128, 0);
                    window.setView(view);
                }
            }

            mapManager.update(event);
        }

        window.clear();

        mapManager.draw(&window);

        window.display();
    }

    return 0;
}