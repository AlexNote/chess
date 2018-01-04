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
            // клетка слева занята чужой фигурой
            if(board->getCellBoard(i-1, coordYcell) == "Black")
            {
                availableSteps[coordYcell][i-1] = true;
                break;
            }
            // клетка слева занята своей фигурой
            if(board->getCellBoard(i-1, coordYcell) == team)
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
            // клетка справа занята чужой фигурой
            if(board->getCellBoard(i+1, coordYcell) == "Black")
            {
                availableSteps[coordYcell][i+1] = true;
                break;
            }
            // клетка справа занята своей фигурой
            if(board->getCellBoard(i+1, coordYcell) == team)
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
            // клетка сверху занята чужой фигурой
            if(board->getCellBoard(coordXcell, i-1) == "Black")
            {
                availableSteps[i-1][coordXcell] = true;
                break;
            }
            // клетка сверху занята своей фигурой
            if(board->getCellBoard(coordXcell, i-1) == team)
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
            // клетка снизу занята чужой фигурой
            if(board->getCellBoard(coordXcell, i+1) == "Black")
            {
                availableSteps[i+1][coordXcell] = true;
                break;
            }
            // клетка снизу занята своей фигурой
            if(board->getCellBoard(coordXcell, i+1) == team)
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
            // клетка слева занята чужой фигурой
            if(board->getCellBoard(i-1, coordYcell) == "White")
            {
                availableSteps[coordYcell][i-1] = true;
                break;
            }
            // клетка слева занята своей фигурой
            if(board->getCellBoard(i-1, coordYcell) == team)
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
            // клетка справа занята чужой фигурой
            if(board->getCellBoard(i+1, coordYcell) == "White")
            {
                availableSteps[coordYcell][i+1] = true;
                break;
            }
            // клетка справа занята своей фигурой
            if(board->getCellBoard(i+1, coordYcell) == team)
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
            // клетка сверху занята чужой фигурой
            if(board->getCellBoard(coordXcell, i-1) == "White")
            {
                availableSteps[i-1][coordXcell] = true;
                break;
            }
            // клетка сверху занята своей фигурой
            if(board->getCellBoard(coordXcell, i-1) == team)
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
            // клетка снизу занята чужой фигурой
            if(board->getCellBoard(coordXcell, i+1) == "White")
            {
                availableSteps[i+1][coordXcell] = true;
                break;
            }
            // клетка снизу занята своей фигурой
            if(board->getCellBoard(coordXcell, i+1) == team)
                break;
        }
    }
    allBeatCells = availableSteps;
}

QVector<QVector<bool> > Rook::getAllBeatCells()
{
    return allBeatCells;
}

//void Rook::setPositionCell(int cellX, int cellY)
//{
//    if (cellX != oldCoordXcell || cellY != oldCoordYcell) // ладья делает шаг на новую клетку
//    {
//        firstStep = false;
//    }
//    coordXcell = cellX;
//    coordYcell = cellY;
//    coordXpx = coordXcell*64 + 63;
//    coordYpx = coordYcell*64 + 63;
//    spriteFigure.setPosition(coordXpx, coordYpx);
//}

bool Rook::isFirstStep()
{
    return firstStep;
}
