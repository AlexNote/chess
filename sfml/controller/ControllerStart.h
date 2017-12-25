#ifndef CONTROLLERSTART_H
#define CONTROLLERSTART_H

#include <SFML/Graphics.hpp>
#include "../model/BtnStart.h"
#include "../model/VectorOfFigures.h"
#include "../model/Board.h"
#include "../model/CaretakerBoard.h"
#include "../model/CaretakerFigure.h"

class ControllerStart
{
private:
    sf::Vector2i cursorPos; // координаты курсора мыши
    bool isGameStart;
public:
    ControllerStart();
    void pushBtn(sf::RenderWindow& window, sf::Event& event, BtnStart& btnStart);

    bool play(VectorOfFigures& figures);
};

#endif // CONTROLLERSTART_H
