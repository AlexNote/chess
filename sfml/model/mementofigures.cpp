#include "MementoFigures.h"

MementoFigures::MementoFigures(std::vector<std::shared_ptr<Figure> > allFigures, QString currentStep, bool enPassant)
{
    this->allFigures = allFigures;
    this->currentStep = currentStep;
    this->enPassant = enPassant;
}

std::vector<std::shared_ptr<Figure> > MementoFigures::getFigures()
{
    return allFigures;
}

QString MementoFigures::getCurrentStep()
{
    return currentStep;
}

bool MementoFigures::getEnPassant()
{
    return enPassant;
}
