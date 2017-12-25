#include "CaretakerFigure.h"

CaretakerFigure* CaretakerFigure::_instance = 0;

CaretakerFigure *CaretakerFigure::Instance()
{
    if (_instance == 0)
        _instance = new CaretakerFigure;
    return _instance;
}

std::shared_ptr<MementoFigures> CaretakerFigure::getFiguresSave()
{
    return figuresSave;
}

void CaretakerFigure::setFiguresSave(const std::shared_ptr<MementoFigures> figures)
{
    this->figuresSave = figures;
}
