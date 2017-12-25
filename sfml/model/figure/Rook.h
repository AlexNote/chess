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
};

#endif // ROOK_H
