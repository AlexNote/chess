#include "King.h"

King::King(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(0, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(0, 0, 64, 64));
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

King::King(const King &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(0, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(0, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    setPositionPixel(copy.coordXpx, copy.coordYpx);
}

std::shared_ptr<Figure> King::clone() const
{
    return std::shared_ptr<Figure>(new King(*this));
}

void King::calcSteps()
{
    Board* board = Board::Instance();

    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
        availableSteps[i][j] = false;
    // шаг влево
    if(coordXcell-1 >= 0)
        if(board->getCellBoard(coordXcell-1, coordYcell) != team)
            availableSteps[coordYcell][coordXcell-1] = true;
    // шаг вправо
    if(coordXcell+1 <= 7)
        if(board->getCellBoard(coordXcell+1, coordYcell) != team)
            availableSteps[coordYcell][coordXcell+1] = true;
    // шаг вверх
    if(coordYcell-1 >= 0)
        if(board->getCellBoard(coordXcell, coordYcell-1) != team)
            availableSteps[coordYcell-1][coordXcell] = true;
    // шаг вниз
    if(coordYcell+1 <= 7)
        if(board->getCellBoard(coordXcell, coordYcell+1) != team)
            availableSteps[coordYcell+1][coordXcell] = true;
    // шаг северо-запад
    if(coordXcell-1 >= 0 && coordYcell-1 >= 0)
        if(board->getCellBoard(coordXcell-1, coordYcell-1) != team)
            availableSteps[coordYcell-1][coordXcell-1] = true;
    // шаг северо-восток
    if(coordXcell+1 <= 7 && coordYcell-1 >= 0)
        if(board->getCellBoard(coordXcell+1, coordYcell-1) != team)
            availableSteps[coordYcell-1][coordXcell+1] = true;
    // шаг юго-восток
    if(coordXcell+1 <= 7 && coordYcell+1 <= 7)
        if(board->getCellBoard(coordXcell+1, coordYcell+1) != team)
            availableSteps[coordYcell+1][coordXcell+1] = true;
    // шаг юго-запад
    if(coordXcell-1 >= 0 && coordYcell+1 <= 7)
        if(board->getCellBoard(coordXcell-1, coordYcell+1) != team)
            availableSteps[coordYcell+1][coordXcell-1] = true;
}
