#include "MapManager.h"

#include <utility>

MapManager::MapManager(SpriteSheet spriteSheet)
    : mSpriteSheet(std::move(spriteSheet)) {

}

bool MapManager::loadFromFile(const std::string &filePath) {
    std::fstream fin(filePath, std::fstream::in);
    if (fin.fail()) return false;

    char ch;
    float xPos = 0;
    float yPos = 0;
    const auto textureSizeF = float(mSpriteSheet.getTextureSize());
    std::string curVal;
    while (fin >> std::noskipws >> ch) {
        if (ch == '\n') {
            addSprite(xPos, yPos, std::stoi(curVal));

            yPos += textureSizeF;
            xPos = 0;
            curVal = "";
        }
        else if (ch == ',') {
            addSprite(xPos, yPos, std::stoi(curVal));

            xPos += textureSizeF;
            curVal = "";
        }
        else {
            curVal += ch;
        }
    }

    addSprite(xPos, yPos, std::stoi(curVal));

    return true;
}

void MapManager::draw(sf::RenderWindow *window) {
    for (auto &tileSprite : mSpriteDefs) {
        window->draw(tileSprite);
    }
}

void MapManager::addSprite(float x, float y, int index) {
    sf::Sprite curSprite = mSpriteSheet.getZeroSprite();
    curSprite.setPosition(x, y);
    mSpriteSheet.spriteTextureByIndex(curSprite, index);
    mSpriteDefs.push_back(curSprite);
}
