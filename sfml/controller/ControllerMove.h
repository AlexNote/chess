#ifndef CONTROLLERMOVE_H
#define CONTROLLERMOVE_H

#include <SFML/Graphics.hpp>
#include "../model/VectorOfFigures.h"
#include "../model/CaretakerBoard.h"
#include "../model/CaretakerFigure.h"

class ControllerMove
{
private:
    //VectorOfFigures figures;
    bool isMove = false; // флаг нажатия курсором на фигуру
    float corX, corY; // корректировка координат нажатия
    //QList<Figure*>::iterator selectFigure = figures.getAllFigures().begin();
    //Figure* selectFigure;
    std::shared_ptr<Figure> selectFigure;
    //QPointer<Figure*> selectFigure;
    sf::Vector2i cursorPos; // координаты курсора мыши
    int cursorCellX;
    int cursorCellY;
    void takeFigure(VectorOfFigures& figures);

public:
    ControllerMove();
    void checkSelect(sf::Event& event, sf::RenderWindow& window, VectorOfFigures& figures);
    void moving();

};

#endif // CONTROLLERMOVE_H
