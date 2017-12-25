#include "Pawn.h"

Pawn::Pawn(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(320, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(320, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    spriteFigure.setPosition(x, y);
    coordXpx = x;
    coordYpx = y;
    coordXcell = x/64;
    coordYcell = y/64;
    oldCoordXcell = coordXcell;
    oldCoordYcell = coordYcell;
    firstStep = true;
}

Pawn::Pawn(const Pawn &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(320, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(320, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }

    setPositionPixel(copy.coordXpx, copy.coordYpx);
}

std::shared_ptr<Figure> Pawn::clone() const
{
    return std::shared_ptr<Figure>(new Pawn(*this));
}

void Pawn::calcSteps()
{
    Board* board = Board::Instance();

    if (coordYcell > 0 && team == "White") // есть доступные ходы для белой пешки
    {
        for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (board->getCellBoard(coordXcell, coordYcell-1) == "") // клетка перед пешкой свободна
            {
                availableSteps[coordYcell-1][coordXcell] = true;
            }
        }
    }


}

bool Pawn::isFirstStep()
{
    return firstStep;
}
