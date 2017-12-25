#include "Rook.h"

Rook::Rook(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(128, 64, 64, 64));

    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(128, 0, 64, 64));
        //spriteFigure.setPosition(cells);
    }
    spriteFigure.setPosition(x, y);
    coordXpx = x;
    coordYpx = y;
    coordXcell = x/64;
    coordYcell = y/64;

    oldCoordXcell = coordXcell;
    oldCoordYcell = coordYcell;
}

Rook::Rook(const Rook &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(128, 64, 64, 64));

    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(128, 0, 64, 64));
        //spriteFigure.setPosition(cells);
    }
    setPositionPixel(copy.coordXpx, copy.coordYpx);
}

std::shared_ptr<Figure> Rook::clone() const
{
    return std::shared_ptr<Figure>(new Rook(*this));
}

void Rook::calcSteps()
{

}
