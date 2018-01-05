#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"
#include <QString>

class Queen : public Figure
{
public:
    Queen(QString team, int x, int y);
    Queen(const Queen& copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
    QVector< QVector<bool> > getAllBeatCells();
    bool isFirstStep();
    QString getType();
    void setPositionCell(int cellX, int cellY);
private:
    QString type = "Queen";
};

#endif // QUEEN_H
