#include "Queen.h"

Queen::Queen(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(64, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(64, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    spriteFigure.setPosition(x, y);
    coordXpx = x;
    coordYpx = y;
    coordXcell = x/64;
    coordYcell = y/64;

    oldCoordXcell = coordXcell;
    oldCoordYcell = coordYcell;
}

Queen::Queen(const Queen &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(64, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(64, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    setPositionPixel(copy.coordXpx, copy.coordYpx);
}

std::shared_ptr<Figure> Queen::clone() const
{
    return std::shared_ptr<Figure>(new Queen(*this));
}

void Queen::calcSteps()
{

}
