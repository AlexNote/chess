#include "Bishop.h"

Bishop::Bishop(QString team, int x, int y)
{
    this->team = team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(256, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(256, 0, 64, 64));
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

Bishop::Bishop(const Bishop &copy)
{
    team = copy.team;
    if (team == "White")
    {
        spriteFigure.setTextureRect(sf::IntRect(256, 64, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }
    else if (team == "Black")
    {
        spriteFigure.setTextureRect(sf::IntRect(256, 0, 64, 64));
        //spriteFigure.setPosition(sf::Vector2f(30, 30));
    }

    setPositionPixel(copy.coordXpx, copy.coordYpx);

}

std::shared_ptr<Figure> Bishop::clone() const
{
    return std::shared_ptr<Figure>(new Bishop(*this));
}

void Bishop::calcSteps()
{
    Board* board = Board::Instance();

    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
        availableSteps[i][j] = false;

    // формирование ходов для белого слона
    if (team == "White")
    {
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

    // формирование ходов для черного слона
    if (team == "Black")
    {
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

QVector<QVector<bool> > Bishop::getAllBeatCells()
{
    return allBeatCells;
}
