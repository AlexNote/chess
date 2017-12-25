#include "Figure.h"

Figure::Figure()
{
    textureFigure.loadFromFile("figures.png");
    spriteFigure.setTexture(textureFigure);
    spriteFigure.setOrigin(32, 32);
}

Figure::Figure(const Figure &)
{
    textureFigure.loadFromFile("figures.png");
    spriteFigure.setTexture(textureFigure);
    spriteFigure.setOrigin(32, 32);
}

void Figure::setPositionPixel(int x, int y)
{
    coordXpx = x;
    coordYpx = y;
    spriteFigure.setPosition(coordXpx, coordYpx);

    coordXcell = (x-31)/64;
    coordYcell = (y-31)/64;
}

void Figure::setPositionCell()
{
    coordXpx = coordXcell*64 + 63;
    coordYpx = coordYcell*64 + 63;
    spriteFigure.setPosition(coordXpx, coordYpx);
}

void Figure::setPositionCell(int cellX, int cellY)
{
    coordXcell = cellX;
    coordYcell = cellY;
    coordXpx = coordXcell*64 + 63;
    coordYpx = coordYcell*64 + 63;
    spriteFigure.setPosition(coordXpx, coordYpx);
}

void Figure::setOldPositionCell()
{
    oldCoordXcell = coordXcell;
    oldCoordYcell = coordYcell;
}

void Figure::setCells(int x, int y)
{
    coordXcell = (x-31)/64;
    coordYcell = (y-31)/64;
}

sf::Sprite Figure::getFigure()
{
    return spriteFigure;
}

sf::Vector2f Figure::getPosition()
{
    return spriteFigure.getPosition();
}

int Figure::getXcell()
{
    return coordXcell;
}

int Figure::getYcell()
{
    return coordYcell;
}

int Figure::getOldXcell()
{
    return oldCoordXcell;
}

int Figure::getOldYcell()
{
    return oldCoordYcell;
}

QString Figure::getTeam()
{
    return team;
}

