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
    void draw(sf::RenderWindow *window);

private:
    SpriteSheet mSpriteSheet;
    std::vector<sf::Sprite> mSpriteDefs;

    void addSprite(float x, float y, int index);
};


#endif //PLAYGROUND_MAPMANAGER_H
