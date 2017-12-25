#ifndef CARETAKERFIGURE_H
#define CARETAKERFIGURE_H

#include "MementoFigures.h"

class CaretakerFigure
{
private:
    CaretakerFigure() = default;
    ~CaretakerFigure() = default;
    CaretakerFigure(const CaretakerFigure&) = delete;
    CaretakerFigure& operator=(const CaretakerFigure&) = delete;
    static CaretakerFigure* _instance;

    std::shared_ptr<MementoFigures> figuresSave;

public:
    static CaretakerFigure* Instance();

    std::shared_ptr<MementoFigures> getFiguresSave();
    void setFiguresSave(const std::shared_ptr<MementoFigures> figures);

};

#endif // CARETAKERFIGURE_H
