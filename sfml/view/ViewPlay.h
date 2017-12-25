#ifndef VIEWPLAY_H
#define VIEWPLAY_H

#include <SFML/Graphics.hpp>
#include <../model/VectorOfFigures.h>

class ViewPlay
{

public:
    ViewPlay() = default;
    //void playGame(sf::RenderWindow& window, const QList<Figure *> &figures);
    //void playGame(sf::RenderWindow& window, const std::vector<Figure *> &figures);
    void playGame(sf::RenderWindow& window, VectorOfFigures &figures);
};

#endif // VIEWPLAY_H
