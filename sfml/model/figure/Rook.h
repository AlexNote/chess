#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"
#include <QString>

class Rook : public Figure
{
public:
    Rook(QString team, int x, int y);
    Rook(const Rook& copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
    void setPositionCell(int cellX, int cellY); // установка игровой позиции по позиции курсора

private:
    bool isFirstStep();
    bool firstStep = true;
    QString type = "Rook";
};

#endif // ROOK_H
