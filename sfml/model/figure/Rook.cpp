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
    Board* board = Board::Instance();

    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
        availableSteps[i][j] = false;
    // формирование ходов для белой ладьи
    if (team == "White")
    {
        // горизонталь влево
        for (int i = coordXcell; i > 0; i--)
        {
            //клетка слева свободна
            if(board->getCellBoard(i-1, coordYcell) == "")
            {
                availableSteps[coordYcell][i-1] = true;
            }
            // клетка слева занята черной фигурой
            if(board->getCellBoard(i-1, coordYcell) == "Black")
            {
                availableSteps[coordYcell][i-1] = true;
                break;
            }
            // клетка слева занята белой фигурой
            if(board->getCellBoard(i-1, coordYcell) == "White")
                break;
        }
        // горизонталь вправо
        for (int i = coordXcell; i < 7; i++)
        {
            //клетка справо свободна
            if(board->getCellBoard(i+1, coordYcell) == "")
            {
                availableSteps[coordYcell][i+1] = true;
            }
            // клетка справа занята черной фигурой
            if(board->getCellBoard(i+1, coordYcell) == "Black")
            {
                availableSteps[coordYcell][i+1] = true;
                break;
            }
            // клетка справа занята белой фигурой
            if(board->getCellBoard(i+1, coordYcell) == "White")
                break;
        }
        // вертикаль вверх
        for (int i = coordYcell; i > 0; i--)
        {
            //клетка сверху свободна
            if(board->getCellBoard(coordXcell, i-1) == "")
            {
                availableSteps[i-1][coordXcell] = true;
            }
            // клетка сверху занята черной фигурой
            if(board->getCellBoard(coordXcell, i-1) == "Black")
            {
                availableSteps[i-1][coordXcell] = true;
                break;
            }
            // клетка сверху занята белой фигурой
            if(board->getCellBoard(coordXcell, i-1) == "White")
                break;
        }
        // вертикаль вниз
        for (int i = coordYcell; i < 7; i++)
        {
            //клетка снизу свободна
            if(board->getCellBoard(coordXcell, i+1) == "")
            {
                availableSteps[i+1][coordXcell] = true;
            }
            // клетка снизу занята черной фигурой
            if(board->getCellBoard(coordXcell, i+1) == "Black")
            {
                availableSteps[i+1][coordXcell] = true;
                break;
            }
            // клетка снизу занята белой фигурой
            if(board->getCellBoard(coordXcell, i+1) == "White")
                break;
        }
    }

    // формирование ходов для черной ладьи
    if (team == "Black")
    {
        // горизонталь влево
        for (int i = coordXcell; i > 0; i--)
        {
            //клетка слева свободна
            if(board->getCellBoard(i-1, coordYcell) == "")
            {
                availableSteps[coordYcell][i-1] = true;
            }
            // клетка слева занята белой фигурой
            if(board->getCellBoard(i-1, coordYcell) == "White")
            {
                availableSteps[coordYcell][i-1] = true;
                break;
            }
            // клетка слева занята черной фигурой
            if(board->getCellBoard(i-1, coordYcell) == "Black")
                break;
        }
        // горизонталь вправо
        for (int i = coordXcell; i < 7; i++)
        {
            //клетка справо свободна
            if(board->getCellBoard(i+1, coordYcell) == "")
            {
                availableSteps[coordYcell][i+1] = true;
            }
            // клетка справа занята белой фигурой
            if(board->getCellBoard(i+1, coordYcell) == "White")
            {
                availableSteps[coordYcell][i+1] = true;
                break;
            }
            // клетка справа занята черной фигурой
            if(board->getCellBoard(i+1, coordYcell) == "Black")
                break;
        }
        // вертикаль вверх
        for (int i = coordYcell; i > 0; i--)
        {
            //клетка сверху свободна
            if(board->getCellBoard(coordXcell, i-1) == "")
            {
                availableSteps[i-1][coordXcell] = true;
            }
            // клетка сверху занята белой фигурой
            if(board->getCellBoard(coordXcell, i-1) == "White")
            {
                availableSteps[i-1][coordXcell] = true;
                break;
            }
            // клетка сверху занята черной фигурой
            if(board->getCellBoard(coordXcell, i-1) == "Black")
                break;
        }
        // вертикаль вниз
        for (int i = coordYcell; i < 7; i++)
        {
            //клетка снизу свободна
            if(board->getCellBoard(coordXcell, i+1) == "")
            {
                availableSteps[i+1][coordXcell] = true;
            }
            // клетка снизу занята белой фигурой
            if(board->getCellBoard(coordXcell, i+1) == "White")
            {
                availableSteps[i+1][coordXcell] = true;
                break;
            }
            // клетка снизу занята черной фигурой
            if(board->getCellBoard(coordXcell, i+1) == "Black")
                break;
        }
    }
}
