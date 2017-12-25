#ifndef BTNSTART_H
#define BTNSTART_H

#include <SFML/Graphics.hpp>

class BtnStart
{
private:
    sf::Image imageStart;
    sf::Texture textureStart;
    sf::Sprite spriteStart;
public:
    BtnStart();
    sf::Sprite getBtnStart();
};

#endif // BTNSTART_H
