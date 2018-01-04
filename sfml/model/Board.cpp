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


