#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"
#include <QString>

class Pawn : public Figure
{
    bool firstStep;
public:
    Pawn(QString team, int x, int y);
    Pawn(const Pawn&copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
    bool isFirstStep();
};

#endif // PAWN_H
