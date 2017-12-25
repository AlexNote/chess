#include "MementoBoard.h"

MementoBoard::MementoBoard(QVector<QVector<QString> > board)
{
    this->board = board;
}

QVector<QVector<QString> > MementoBoard::getBoard()
{
    return board;
}
