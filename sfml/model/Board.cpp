#include "Board.h"

Board* Board::_instance = 0;

Board* Board::Instance() {
    if (_instance == 0)
    {
        _instance = new Board();
        _instance->textureBoard.loadFromFile("board.jpg");
        _instance->spriteBoard.setTexture(_instance->textureBoard);
//        _instance->board = {
//            {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
//            {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
//            {"",      "",      "",      "",      "",      "",      "",      ""     },
//            {"",      "",      "",      "",      "",      "",      "",      ""     },
//            {"",      "",      "",      "",      "",      "",      "",      ""     },
//            {"",      "",      "",      "",      "",      "",      "",      ""     },
//            {"White", "White", "White", "White", "White", "White", "White", "White"},
//            {"White", "White", "White", "White", "White", "White", "White", "White"} };
    }
    return _instance;
}

sf::Sprite Board::getBoard()
{
    return spriteBoard;
}

QString Board::getCellBoard(int x, int y)
{
    return board[y][x];
}

void Board::setCellBoard(int x, int y, QString team)
{
    board[y][x] = team;
}

void Board::load(std::shared_ptr<MementoBoard> boardSave)
{
    board = boardSave->getBoard();
}

std::shared_ptr<MementoBoard> Board::save()
{
    return std::shared_ptr<MementoBoard>(new MementoBoard(board));
}

bool Board::getWhiteBit(int x, int y)
{
    return whiteBitCells[y][x];
}

bool Board::getBlackBit(int x, int y)
{
    return blackBitCells[y][x];
}

void Board::setBitCells(VectorOfFigures &figures)
{
    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
        whiteBitCells[i][j] = false;
        blackBitCells[i][j] = false;
    }

    // просмотр всех фигур на доске
    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        QVector<QVector<bool> > steps = (*iterFigure)->getAllSteps();
        // текущая фигура принадлежит белой команде
        if ((*iterFigure)->getTeam() == "White")
        {
            for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                whiteBitCells[i][j] = steps[i][j];
            }
        }
        // текущая фигура принадлежит черной команде
        else
        {
            for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                blackBitCells[i][j] = steps[i][j];
            }
        }

    }
}
