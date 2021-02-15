#include "MapManager.h"

#include <utility>

void MapManager::addSprite(float x, float y, int index) {
    sf::Sprite curSprite = mSpriteSheet.getZeroSprite();
    curSprite.setPosition(x, y);
    mSpriteSheet.spriteTextureByIndex(curSprite, index);
    mSpriteDefs.push_back(curSprite);

    const auto textureSizeF = float(mSpriteSheet.getTextureSize());

    sf::RectangleShape border;
    border.setSize(sf::Vector2f(textureSizeF - 5.0f, textureSizeF - 5.0f));
    border.setPosition(x + 5.0f, y + 5.0f);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineColor(sf::Color::Magenta);
    border.setOutlineThickness(5.0f);
    mSpriteBorderDefs.push_back(border);

    sf::Text text(std::to_string(index), mFont);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setLetterSpacing(2);

    float textXPos = (x + (textureSizeF / 2)) - (text.getLocalBounds().width / 2);
    float textYPos = (y + (textureSizeF / 2)) - (text.getLocalBounds().height / 2);

    text.setPosition(textXPos, textYPos);
    mSpriteTextDefs.push_back(text);
}

MapManager::MapManager(SpriteSheet spriteSheet)
    : mSpriteSheet(std::move(spriteSheet)) {
}

bool MapManager::loadFromFile(const std::string &filePath) {
    std::fstream fin(filePath, std::fstream::in);
    if (fin.fail()) return false;

    if (!mFont.loadFromFile("le-murmure.otf")) return false;

    char ch;
    float xPos = 0;
    float yPos = 0;
    const auto textureSizeF = float(mSpriteSheet.getTextureSize());
    std::string curVal;
    int copyVal = 0;
    int copyCount = 0;
    while (fin >> std::noskipws >> ch) {
        if (ch == '*') {
            copyVal = std::stoi(curVal);
            copyCount = -1;
            curVal = "";
        }
        else if (ch == '\n') {
            if (copyCount == -1) {
                copyCount = std::stoi(curVal);
                while (copyCount > 0) {
                    addSprite(xPos, yPos, copyVal);
                    xPos += textureSizeF;

                    copyCount--;
                }

                copyVal = 0;
            }
            else {
                addSprite(xPos, yPos, std::stoi(curVal));
            }

            yPos += textureSizeF;
            xPos = 0;
            curVal = "";
        }
        else if (ch == ',') {
            if (copyCount == -1) {
                copyCount = std::stoi(curVal);
                while (copyCount > 0) {
                    addSprite(xPos, yPos, copyVal);
                    xPos += textureSizeF;

                    copyCount--;
                }

                copyVal = 0;
                curVal = "";
            }
            else {
                addSprite(xPos, yPos, std::stoi(curVal));

                xPos += textureSizeF;
                curVal = "";
            }
        }
        else {
            curVal += ch;
        }
    }

    addSprite(xPos, yPos, std::stoi(curVal));

    return true;
}

void MapManager::update(const sf::Event& event) {
//    if (event.type == sf::Event::MouseMoved) {
//        for (int i = 0; i < mSpriteDefs.size(); i++) {
//            if (mSpriteDefs[i].getGlobalBounds().contains(
//                    event.mouseMove.x, event.mouseMove.y)) {
//                std::cout << "Hovering item at index: " << i << std::endl;
//                break;
//            }
//        }
//    }
}

void MapManager::draw(sf::RenderWindow *window) {
    for (auto &tileSprite : mSpriteDefs) {
        window->draw(tileSprite);
    }

    for (auto &border : mSpriteBorderDefs) {
        window->draw(border);
    }

    for (auto &textSprite : mSpriteTextDefs) {
        window->draw(textSprite);
    }
}