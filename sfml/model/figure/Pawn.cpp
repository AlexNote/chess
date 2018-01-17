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
}

Pawn::Pawn(const Pawn &copy) : Figure::Figure(copy)
{
    team = copy.team;
    availableSteps = copy.availableSteps;
    allBeatCells = copy.allBeatCells;
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

void Pawn::calcSteps() // формирование матрицы теоретически доступных ходов
{
    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
        availableSteps[i][j] = false;
        allBeatCells[i][j] = false;
    }


    Board* board = Board::Instance();

    if (coordYcell > 0 && team == "White") // есть доступные ходы для белой пешки
    {
        // если клетка перед пешкой свободна
        if (board->getCellBoard(coordXcell, coordYcell-1) == "")
        {
            availableSteps[coordYcell-1][coordXcell] = true;
            allBeatCells[coordYcell-1][coordXcell] = false;
            if (isFirstStep()) // если это первый ход пешки
            {
                // если две клетки перед пешкой свободны
                if (board->getCellBoard(coordXcell, coordYcell-2) == "")
                {
                    availableSteps[coordYcell-2][coordXcell] = true;
                    allBeatCells[coordYcell-2][coordXcell] = false;
                }
            }
        }
        //пешка с левого края
        if(coordXcell == 0)
        {
            allBeatCells[coordYcell-1][coordXcell+1] = true;
            // пешка может забрать черную фигуру справа
            if(board->getCellBoard(coordXcell+1, coordYcell-1) == "Black")
            {
                availableSteps[coordYcell-1][coordXcell+1] = true;
            }
        }
        //пешка с правого края
        if (coordXcell == 7)
        {
            allBeatCells[coordYcell-1][coordXcell-1] = true;
            // пешка может забрать черную фигуру слева
            if(board->getCellBoard(coordXcell-1, coordYcell-1) == "Black")
            {
                availableSteps[coordYcell-1][coordXcell-1] = true;
            }
        }
        //пешка не с краю
        if (coordXcell != 0 && coordXcell != 7)
        {
            allBeatCells[coordYcell-1][coordXcell+1] = true;
            allBeatCells[coordYcell-1][coordXcell-1] = true;
            // пешка может забрать черную фигуру справа
            if(board->getCellBoard(coordXcell+1, coordYcell-1) == "Black")
            {
                availableSteps[coordYcell-1][coordXcell+1] = true;
            }
            // пешка может забрать черную фигуру слева
            if(board->getCellBoard(coordXcell-1, coordYcell-1) == "Black")
            {
                availableSteps[coordYcell-1][coordXcell-1] = true;
            }
        }
    }

    if (coordYcell < 7 && team == "Black") // есть доступные ходы для черной пешки
    {
        // если клетка перед пешкой свободна
        if (board->getCellBoard(coordXcell, coordYcell+1) == "")
        {
            availableSteps[coordYcell+1][coordXcell] = true;
            allBeatCells[coordYcell+1][coordXcell] = false;
            if (isFirstStep()) // если это первый ход пешки
            {
                // если две клетки перед пешкой свободны
                if (board->getCellBoard(coordXcell, coordYcell+2) == "")
                {
                    availableSteps[coordYcell+2][coordXcell] = true;
                    allBeatCells[coordYcell+2][coordXcell] = false;
                }
            }
        }
        //пешка с левого края
        if(coordXcell == 0)
        {
            allBeatCells[coordYcell+1][coordXcell+1] = true;
            // пешка может забрать белую фигуру справа
            if(board->getCellBoard(coordXcell+1, coordYcell+1) == "White")
            {
                availableSteps[coordYcell+1][coordXcell+1] = true;
            }
        }
        //пешка с правого края
        if (coordXcell == 7)
        {
            allBeatCells[coordYcell+1][coordXcell-1] = true;
            // пешка может забрать белую фигуру слева
            if(board->getCellBoard(coordXcell-1, coordYcell+1) == "White")
            {
                availableSteps[coordYcell+1][coordXcell-1] = true;
            }
        }
        //пешка не с краю
        if (coordXcell != 0 && coordXcell != 7)
        {
            allBeatCells[coordYcell+1][coordXcell+1] = true;
            allBeatCells[coordYcell+1][coordXcell-1] = true;
            // пешка может забрать белую фигуру справа
            if(board->getCellBoard(coordXcell+1, coordYcell+1) == "White")
            {
                availableSteps[coordYcell+1][coordXcell+1] = true;
            }
            // пешка может забрать белую фигуру слева
            if(board->getCellBoard(coordXcell-1, coordYcell+1) == "White")
            {
                availableSteps[coordYcell+1][coordXcell-1] = true;
            }
        }
    }
}

QVector<QVector<bool> > Pawn::getAllBeatCells()
{
    return allBeatCells;
}

QString Pawn::getType()
{
    return type;
}

void Pawn::setPositionCell(int cellX, int cellY)
{
    coordXcell = cellX;
    coordYcell = cellY;
    coordXpx = coordXcell*64 + 63;
    coordYpx = coordYcell*64 + 63;
    spriteFigure.setPosition(coordXpx, coordYpx);
}

bool Pawn::isFirstStep()
{
    if (team == "White"){
        if (coordYcell == 6) // белая пешка еще не ходила
            return true;
        else return false;
    }
    if (team == "Black"){
        if (coordYcell == 1) // черная пешка еще не ходила
            return true;
        else return false;
    }
    return false;
}
