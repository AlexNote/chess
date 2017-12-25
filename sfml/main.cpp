
#include "model/Board.h"
//#include "figure/Figure.h"
#include "view/ViewPlay.h"
#include "view/ViewStart.h"
#include "model/BtnStart.h"

#include "controller/ControllerMove.h"
#include "controller/ControllerStart.h"
#include "controller/ControllerTake.h"
#include <iostream>

int main()
{
    sf::RenderWindow window;//(sf::VideoMode(572, 572), "Chess");
    window.create(sf::VideoMode(572, 572), "Chess", sf::Style::Titlebar|sf::Style::Close);
    Board* board = Board::Instance();
    VectorOfFigures figures;
    BtnStart btnStart;

    ControllerMove controllerMove;
    ControllerStart controllerStart;
   // ControllerTake controllerTake;


    ViewPlay play;
    ViewStart start;

    while (window.isOpen())                                              //абстрактная фабрика
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (controllerStart.play(figures))
            {
                controllerMove.checkSelect(event, window, figures); // выбор фигуры
               // controllerTake.takeFigure(figures); // взятие фигуры
            }
            else controllerStart.pushBtn(window, event, btnStart);

        }

        if (controllerStart.play(figures))
            controllerMove.moving(); // движение фигуры

        window.clear();
        window.draw(board->getBoard());

        if (controllerStart.play(figures))
            play.playGame(window, figures);

        else start.startGame(window, btnStart.getBtnStart());

        window.display();
    }

    return 0;

}
