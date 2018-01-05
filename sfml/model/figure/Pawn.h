#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"
#include <QString>

class Pawn : public Figure
{
public:
    Pawn(QString team, int x, int y);
    Pawn(const Pawn&copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
    QVector< QVector<bool> > getAllBeatCells();
    QString getType();
    void setPositionCell(int cellX, int cellY);
private:

    bool isFirstStep();
    QString type = "Pawn";
};

#endif // PAWN_H
