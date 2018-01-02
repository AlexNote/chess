#include "ControllerMove.h"
#include <QDebug>
#include <../model/Board.h>

void ControllerMove::checkSelect(sf::Event& event, sf::RenderWindow& window, VectorOfFigures& figures)
{
    cursorPos = sf::Mouse::getPosition(window); //  получение координат курсора мыши
    int counter = 0; // для перемещения фигуры в конец списка
    Board* board = Board::Instance();
    CaretakerBoard* caretakerBoard = CaretakerBoard::Instance();
    CaretakerFigure* caretakerFigure = CaretakerFigure::Instance();
    if (event.type == sf::Event::MouseButtonPressed) // если нажата клавиша мыши
        if (event.mouseButton.button == sf::Mouse::Left)
        {

            //qDebug() << board->getCellBoard(0,0);
//            qDebug() << board->getCellBoard(1,1);
//            qDebug() << board->getCellBoard(2,2);
//            qDebug() << board->getCellBoard(7,7);

            for (size_t iterFigure = 0, size = figures.getAllFigures().size(); iterFigure < size; iterFigure++)
            {
                if (figures.getAllFigures()[iterFigure]->getFigure().getGlobalBounds().contains(cursorPos.x, cursorPos.y)) // курсор над нужной фигурой
                {
                    selectFigure = figures.getAllFigures()[iterFigure];
                    if (figures.getCurrentStep() == selectFigure->getTeam()) // очередной ход
                    {
                        caretakerBoard->setBoardSave(board->save()); // помещение хранителя доски в опекуна доски
                        caretakerFigure->setFiguresSave(figures.save()); // помещение хранителя фигур в опекуна фигур
                        //qDebug() << selectFigure->getAvailableStep();
                        selectFigure->setOldPositionCell();
                        corX = cursorPos.x - selectFigure->getPosition().x;
                        corY = cursorPos.y - selectFigure->getPosition().y;
                        isMove = true;
                        figures.replaceBack(counter); // перемещение выбранной фигуры в конец вектора
                        break;
                    }
                }
                counter++; // какая по счету фигура
            }

        }
    if (event.type == sf::Event::MouseButtonReleased) // кнопка мыши отпущена
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (isMove)
            {
                isMove = false;
                selectFigure->setPositionCell();
                takeFigure(figures);
            }

        }
}

void ControllerMove::moving()
{
    if (isMove) // движение фигуры
    {
        selectFigure->setPositionPixel(cursorPos.x - corX, cursorPos.y - corY);
    }
}

void ControllerMove::takeFigure(VectorOfFigures& figures)
{
    Board* board = Board::Instance();

    int oldPosX = selectFigure->getOldXcell();
    int oldPosY = selectFigure->getOldYcell();
    int newPosX = selectFigure->getXcell();
    int newPosY = selectFigure->getYcell();
    QString team = selectFigure->getTeam();
    bool differents = false;
    if (selectFigure->getPosition().x < 30 || selectFigure->getPosition().y < 30 || selectFigure->getPosition().x > 542 || selectFigure->getPosition().y > 542)
    {
        selectFigure->setPositionCell(oldPosX, oldPosY);
    }
    else if ( (oldPosX != newPosX) || (oldPosY != newPosY) ) // фигура была передвинута
    {
        if (selectFigure->getAvailableStep(newPosX, newPosY)) // если фигура может встать в эту клетку
        {
            if (board->getCellBoard(newPosX, newPosY) == "") // клетка свободна
            {
                selectFigure->setPositionCell(newPosX, newPosY);
                board->setCellBoard(oldPosX, oldPosY, "");
                board->setCellBoard(newPosX, newPosY, team);
                team == "White" ? figures.setCurrentStep("Black") : figures.setCurrentStep("White");
            }
            else if (board->getCellBoard(newPosX, newPosY) == team) // клетка занята своей фигурой. поставить обратно
            {
                selectFigure->setPositionCell(oldPosX, oldPosY);
            }
            else // клетка занята чужой фигурой. найти эту фигуру в векторе
            {
                size_t iterFigure = 0;
                size_t size = figures.getAllFigures().size();

                for (iterFigure = 0, size = figures.getAllFigures().size() ; iterFigure < size; iterFigure++)
                {
                    int takenX = figures.getAllFigures()[iterFigure]->getXcell();
                    int takenY = figures.getAllFigures()[iterFigure]->getYcell();
                    if ( (newPosX == takenX) && (newPosY == takenY) ) // найдена забиаемая фигура
                    {
                        differents = true;
                        break;
                    }
                }
                if (differents) // забрать фигуру. удалить её из вектора фигур
                {
                    figures.getAllFigures().erase(figures.getAllFigures().begin()+iterFigure); // удалить фигуру iterFigure
                    board->setCellBoard(oldPosX, oldPosY, "");
                    board->setCellBoard(newPosX, newPosY, team);
                    team == "White" ? figures.setCurrentStep("Black") : figures.setCurrentStep("White");
                }
            }
        }
        else
        {
            selectFigure->setPositionCell(oldPosX, oldPosY);
        }
    }

    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        (*iterFigure)->calcSteps();
    }
}

ControllerMove::ControllerMove()
{
}
