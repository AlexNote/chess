#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"
#include <QString>

class Knight : public Figure
{
public:
    Knight(QString team, int x, int y);
    Knight(const Knight& copy);
    std::shared_ptr<Figure> clone() const;
    void calcSteps();

private:
    QString type = "Knight";
};

#endif // KNIGHT_H
