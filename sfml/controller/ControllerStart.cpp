#include "ControllerStart.h"
#include <QDebug>

ControllerStart::ControllerStart()
{
    isGameStart = false;
}

void ControllerStart::pushBtn(sf::RenderWindow& window, sf::Event& event, BtnStart &btnStart)
{
    cursorPos = sf::Mouse::getPosition(window);

    if (event.type == sf::Event::MouseButtonPressed) // если нажата клавиша мыши
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (btnStart.getBtnStart().getGlobalBounds().contains(cursorPos.x, cursorPos.y))
                isGameStart = true;
        }
    }
}

bool ControllerStart::play(VectorOfFigures &figures, ControllerMove &controllerMove)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        isGameStart = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
    {
        Board* board = Board::Instance();
        CaretakerBoard* caretakerBoard = CaretakerBoard::Instance();
        CaretakerFigure* caretakerFigure = CaretakerFigure::Instance();
        board->load(caretakerBoard->getBoardSave());
        figures.load(caretakerFigure->getFiguresSave());

        for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
        {
            (*iterFigure)->calcSteps();
        }
        controllerMove.setKings(figures);

    }

    return isGameStart;
}
