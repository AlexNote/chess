#ifndef MEMENTOBOARD_H
#define MEMENTOBOARD_H

#include <QVector>
#include <QString>

class MementoBoard
{
private:
    QVector< QVector< QString > > board;
public:
    MementoBoard(QVector< QVector< QString > > board);
    QVector< QVector< QString > > getBoard();

};

#endif // MEMENTOBOARD_H
