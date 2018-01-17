#include "Board.h"
#include <QDebug>
Board* Board::_instance = 0;

Board* Board::Instance() {
    if (_instance == 0)
    {
        _instance = new Board();
        _instance->textureBoard.loadFromFile("board.jpg");
        _instance->spriteBoard.setTexture(_instance->textureBoard);
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

void Board::SHOWBOARD()
{
    for (int i = 0; i < 8; i++)
    {
        qDebug() << board[i][0] << " " << board[i][1] << " " << board[i][2] << " " << board[i][3] << " " << board[i][4] << " " << board[i][5] << " " << board[i][6] << " " << board[i][7];
    }
    qDebug() << "\n";
}


