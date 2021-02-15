#ifndef PLAYGROUND_MAPMANAGER_H
#define PLAYGROUND_MAPMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>

#include "SpriteSheet.h"

class MapManager {
public:
    explicit MapManager(SpriteSheet spriteSheet);
    bool loadFromFile(const std::string &filePath);
    void update(const sf::Event &event);
    void draw(sf::RenderWindow *window);

private:
    SpriteSheet mSpriteSheet;
    std::vector<sf::Sprite> mSpriteDefs;
    std::vector<sf::Text> mSpriteTextDefs;
    std::vector<sf::RectangleShape> mSpriteBorderDefs;
    sf::Font mFont;

    void addSprite(float x, float y, int index);
};


#endif //PLAYGROUND_MAPMANAGER_H
