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
    Board* board = Board::Instance();

    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
        availableSteps[i][j] = false;
    // формирование ходов для белой королевы
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

        // северо-запад
        for(int i = coordXcell, j = coordYcell; i > 0 && j > 0; i--, j--)
        {
            // клетка свободна
            if(board->getCellBoard(i-1, j-1) == "")
            {
                availableSteps[j-1][i-1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i-1, j-1) == "Black")
            {
                availableSteps[j-1][i-1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i-1, j-1) == team)
                break;
        }
        // юго-восток
        for(int i = coordXcell, j = coordYcell; i < 7 && j < 7; i++, j++)
        {
            // клетка свободна
            if(board->getCellBoard(i+1, j+1) == "")
            {
                availableSteps[j+1][i+1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i+1, j+1) == "Black")
            {
                availableSteps[j+1][i+1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i+1, j+1) == team)
                break;
        }
        // северо-восток
        for(int i = coordXcell, j = coordYcell; i < 7 && j > 0; i++, j--)
        {
            // клетка свободна
            if(board->getCellBoard(i+1, j-1) == "")
            {
                availableSteps[j-1][i+1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i+1, j-1) == "Black")
            {
                availableSteps[j-1][i+1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i+1, j-1) == team)
                break;
        }
        // юго-запад
        for(int i = coordXcell, j = coordYcell; i > 0 && j < 7; i--, j++)
        {
            // клетка свободна
            if(board->getCellBoard(i-1, j+1) == "")
            {
                availableSteps[j+1][i-1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i-1, j+1) == "Black")
            {
                availableSteps[j+1][i-1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i-1, j+1) == team)
                break;
        }
    }
    // формирование ходов для черной королевы
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

        // северо-запад
        for(int i = coordXcell, j = coordYcell; i > 0 && j > 0; i--, j--)
        {
            // клетка свободна
            if(board->getCellBoard(i-1, j-1) == "")
            {
                availableSteps[j-1][i-1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i-1, j-1) == "White")
            {
                availableSteps[j-1][i-1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i-1, j-1) == team)
                break;
        }
        // юго-восток
        for(int i = coordXcell, j = coordYcell; i < 7 && j < 7; i++, j++)
        {
            // клетка свободна
            if(board->getCellBoard(i+1, j+1) == "")
            {
                availableSteps[j+1][i+1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i+1, j+1) == "White")
            {
                availableSteps[j+1][i+1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i+1, j+1) == team)
                break;
        }
        // северо-восток
        for(int i = coordXcell, j = coordYcell; i < 7 && j > 0; i++, j--)
        {
            // клетка свободна
            if(board->getCellBoard(i+1, j-1) == "")
            {
                availableSteps[j-1][i+1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i+1, j-1) == "White")
            {
                availableSteps[j-1][i+1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i+1, j-1) == team)
                break;
        }
        // юго-запад
        for(int i = coordXcell, j = coordYcell; i > 0 && j < 7; i--, j++)
        {
            // клетка свободна
            if(board->getCellBoard(i-1, j+1) == "")
            {
                availableSteps[j+1][i-1] = true;
            }
            // клетка занята чужой фигурой
            if(board->getCellBoard(i-1, j+1) == "White")
            {
                availableSteps[j+1][i-1] = true;
                break;
            }
            // клетка занято своей фигурой
            if(board->getCellBoard(i-1, j+1) == team)
                break;
        }
    }
    allBeatCells = availableSteps;
}

QVector<QVector<bool> > Queen::getAllBeatCells()
{
    return allBeatCells;
}
