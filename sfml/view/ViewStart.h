#ifndef VIEWSTART_H
#define VIEWSTART_H

#include <SFML/Graphics.hpp>

class ViewStart
{
public:
    ViewStart() = default;
    void startGame(sf::RenderWindow& window, const sf::Sprite& btnSprite);
};

#endif // VIEWSTART_H
