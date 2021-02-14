#ifndef PLAYGROUND_SPRITESHEET_H
#define PLAYGROUND_SPRITESHEET_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class SpriteSheet {
public:
    explicit SpriteSheet(uint8_t textureSize);
    bool loadTextureFromFile(const char *filePath);
    void nextSpriteTexture(sf::Sprite &sprite);
    void previousSpriteTexture(sf::Sprite &sprite);
    void spriteTextureByIndex(sf::Sprite &sprite, int index);
    sf::Sprite getZeroSprite();
    uint8_t getTextureSize() const;
private:
    sf::Texture mTexture;
    uint8_t mTextureSize;
};


#endif //PLAYGROUND_SPRITESHEET_H
