#include "MementoFigures.h"

MementoFigures::MementoFigures(std::vector<std::shared_ptr<Figure> > allFigures, QString currentStep)
{
    this->allFigures = allFigures;
    this->currentStep = currentStep;
}

std::vector<std::shared_ptr<Figure> > MementoFigures::getFigures()
{
    return allFigures;
}

QString MementoFigures::getCurrentStep()
{
    return currentStep;
}
