#ifndef KING_H
#define KING_H

#include "Figure.h"
#include <QString>

class King : public Figure
{
public:
    King(QString team, int x, int y);
    King(const King& copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();
};

#endif // KING_H
