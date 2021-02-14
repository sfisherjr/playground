#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(uint8_t textureSize)
    : mTextureSize(textureSize) {
}

bool SpriteSheet::loadTextureFromFile(const char *filePath) {
    return mTexture.loadFromFile(filePath);
}

void SpriteSheet::nextSpriteTexture(sf::Sprite &sprite) {
    sf::IntRect rect = sprite.getTextureRect();

    if (rect.left >= mTexture.getSize().x - mTextureSize) {
        rect.left = 0;
        rect.top += mTextureSize;

        if (rect.top >= mTexture.getSize().y - mTextureSize) {
            rect.top = 0;
        }
    }
    else {
        rect.left += mTextureSize;
    }

    sprite.setTextureRect(rect);
}

void SpriteSheet::previousSpriteTexture(sf::Sprite &sprite) {
    sf::IntRect rect = sprite.getTextureRect();

    if (rect.left <= 0) {
        rect.left = mTexture.getSize().x - mTextureSize;
        rect.top -= mTextureSize;

        if (rect.top < 0) {
            rect.top = mTexture.getSize().y - mTextureSize;
        }
    }
    else {
        rect.left -= mTextureSize;
    }

    sprite.setTextureRect(rect);
}

sf::Sprite SpriteSheet::getZeroSprite() {
    return sf::Sprite(mTexture, sf::IntRect(0, 0, mTextureSize, mTextureSize));
}

uint8_t SpriteSheet::getTextureSize() const {
    return mTextureSize;
}

void SpriteSheet::spriteTextureByIndex(sf::Sprite &sprite, int index) {
    sf::IntRect rect = sprite.getTextureRect();

    uint16_t itemsPerRow = (mTexture.getSize().x / mTextureSize) - 1;
    rect.left = (index % itemsPerRow) * mTextureSize;
    rect.top = (index / itemsPerRow) * mTextureSize;

    std::cout << index << ": " << rect.left << ", " << rect.top << std::endl;

    std::cout << "Items per row = " << itemsPerRow << std::endl;

    sprite.setTextureRect(rect);
}
