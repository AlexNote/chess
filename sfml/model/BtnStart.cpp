#include "BtnStart.h"

BtnStart::BtnStart()
{
    imageStart.loadFromFile("playGame.png");
    imageStart.createMaskFromColor(sf::Color::White, 0);
    textureStart.loadFromImage(imageStart);
    spriteStart.setTexture(textureStart);
    spriteStart.setOrigin(90, 21);
    spriteStart.setPosition(286, 286);
}

sf::Sprite BtnStart::getBtnStart()
{
    return spriteStart;
}
