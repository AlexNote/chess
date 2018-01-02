#include "Knight.h"

Knight::Knight(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(192, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(192, 0, 64, 64));
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

Knight::Knight(const Knight &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(192, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(192, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }

    setPositionPixel(copy.coordXpx, copy.coordYpx);
}

std::shared_ptr<Figure> Knight::clone() const
{
    return std::shared_ptr<Figure>(new Knight(*this));
}

void Knight::calcSteps()
{
    Board* board = Board::Instance();

    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
        availableSteps[i][j] = false;
    // формирование ходов для коня (8 ходов)
    // два хода слева
    if (coordXcell-2 >= 0)
    {
        if(coordYcell-1 >= 0)   // 1
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell-2, coordYcell-1) != team)
            {
                availableSteps[coordYcell-1][coordXcell-2] = true;
            }
        }

        if(coordYcell+1 <= 7)   // 2
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell-2, coordYcell+1) != team)
            {
                availableSteps[coordYcell+1][coordXcell-2] = true;
            }
        }
    }
    // два хода справа
    if (coordXcell+2 <= 7)
    {
        if(coordYcell-1 >= 0)   // 3
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell+2, coordYcell-1) != team)
            {
                availableSteps[coordYcell-1][coordXcell+2] = true;
            }
        }

        if(coordYcell+1 <= 7)   // 4
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell+2, coordYcell+1) != team)
            {
                availableSteps[coordYcell+1][coordXcell+2] = true;
            }
        }
    }
    // два хода сверху
    if (coordYcell-2 >= 0)
    {
        if(coordXcell-1 >= 0)   // 5
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell-1, coordYcell-2) != team)
            {
                availableSteps[coordYcell-2][coordXcell-1] = true;
            }
        }

        if(coordXcell+1 <= 7)   // 6
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell+1, coordYcell-2) != team)
            {
                availableSteps[coordYcell-2][coordXcell+1] = true;
            }
        }
    }
    // два хода снизу
    if (coordYcell+2 <= 7)
    {
        if(coordXcell-1 >= 0)   // 7
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell-1, coordYcell+2) != team)
            {
                availableSteps[coordYcell+2][coordXcell-1] = true;
            }
        }

        if(coordXcell+1 <= 7)   // 8
        {
            // клетка свободна или занята чужой фигурой
            if(board->getCellBoard(coordXcell+1, coordYcell+2) != team)
            {
                availableSteps[coordYcell+2][coordXcell+1] = true;
            }
        }
    }
}
