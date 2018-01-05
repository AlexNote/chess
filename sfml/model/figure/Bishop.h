#ifndef BISHOP_H
#define BISHOP_H

#include <QString>
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(QString team, int x, int y);
    Bishop(const Bishop&copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
    QVector< QVector<bool> > getAllBeatCells();
    bool isFirstStep();
    QString getType();
    void setPositionCell(int cellX, int cellY);
private:
    QString type = "Bishop";
};

#endif // BISHOP_H
