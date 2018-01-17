#ifndef MEMENTOFIGURES_H
#define MEMENTOFIGURES_H

#include <vector>
#include <QString>
#include <memory>
#include "figure/Figure.h"

class MementoFigures
{
private:
    std::vector< std::shared_ptr<Figure> > allFigures;
    QString currentStep;
    bool enPassant;

public:
    MementoFigures(std::vector<std::shared_ptr<Figure> > allFigures, QString currentStep, bool enPassant);
    std::vector< std::shared_ptr<Figure> > getFigures();
    QString getCurrentStep();
    bool getEnPassant();
};

#endif // MEMENTOFIGURES_H
