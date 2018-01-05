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
                        setBeatCells(figures);
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
    CaretakerBoard* caretakerBoard = CaretakerBoard::Instance();
    CaretakerFigure* caretakerFigure = CaretakerFigure::Instance();

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
        //рокировка. Если король делает свой первый шаг
        if (selectFigure->getType() == "King" && selectFigure->isFirstStep())
        {
            // короткая рокировка
            if (newPosX == oldPosX+2 && newPosY == oldPosY){
                // если клтки для рокировки свободны
                if (board->getCellBoard(oldPosX+1, newPosY) == "" && board->getCellBoard(newPosX, newPosY) == "")
                {
                    // может ли рокироваться ладья
                    // поиск ладьи
                    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
                    {
                        if ((*iterFigure)->getXcell() == newPosX + 1 && (*iterFigure)->getYcell() == newPosY &&
                                (*iterFigure)->getType() == "Rook" && (*iterFigure)->getTeam() == team &&
                                (*iterFigure)->isFirstStep())
                        {
                            // ладья найдена
                            castlingFigure = (*iterFigure);
                            break;
                        }
                    }
                    // если была найдена ладья для рокировки
                    if (castlingFigure != nullptr)
                    {
                        if (team == "White")
                        {
                            // если король не под шахом и клетки для рокировки не находятся под ударом
                            if (!blackBeatCells[oldPosY][oldPosX] && !blackBeatCells[oldPosY][oldPosX+1] && !blackBeatCells[newPosY][newPosX])
                            {
                                // тогда король может рокироваться коротко
                                selectFigure->setAvailableStep(newPosX, newPosY);
                            }
                            else castlingFigure = nullptr;
                        }
                        if (team == "Black")
                        {
                            // если король не под шахом и клетки для рокировки не находятся под ударом
                            if (!whiteBeatCells[oldPosY][oldPosX] && !whiteBeatCells[oldPosY][oldPosX+1] && !whiteBeatCells[newPosY][newPosX])
                            {
                                // тогда король может рокироваться коротко
                                selectFigure->setAvailableStep(newPosX, newPosY);
                            }
                            else castlingFigure = nullptr;
                        }
                    }

                }
            }
            // длинная рокировка
            if (newPosX == oldPosX-2 && newPosY == oldPosY){
                // если клтки для рокировки свободны
                if (board->getCellBoard(oldPosX-1, newPosY) == "" && board->getCellBoard(newPosX, newPosY) == "")
                {
                    // может ли рокироваться ладья
                    // поиск ладьи
                    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
                    {
                        if ((*iterFigure)->getXcell() == newPosX-2 && (*iterFigure)->getYcell() == newPosY &&
                                (*iterFigure)->getType() == "Rook" && (*iterFigure)->getTeam() == team &&
                                (*iterFigure)->isFirstStep())
                        {
                            // ладья найдена
                            castlingFigure = (*iterFigure);
                            break;
                        }
                    }
                    // если была найдена ладья для рокировки
                    if (castlingFigure != nullptr)
                    {
                        if (team == "White")
                        {
                            // если король не под шахом и клетки для рокировки не находятся под ударом
                            if (!blackBeatCells[oldPosY][oldPosX] && !blackBeatCells[oldPosY][oldPosX-1] && !blackBeatCells[newPosY][newPosX])
                            {
                                // тогда король может рокироваться коротко
                                selectFigure->setAvailableStep(newPosX, newPosY);
                            }
                            else castlingFigure = nullptr;
                        }
                        if (team == "Black")
                        {
                            // если король не под шахом и клетки для рокировки не находятся под ударом
                            if (!whiteBeatCells[oldPosY][oldPosX] && !whiteBeatCells[oldPosY][oldPosX-1] && !whiteBeatCells[newPosY][newPosX])
                            {
                                // тогда король может рокироваться коротко
                                selectFigure->setAvailableStep(newPosX, newPosY);
                            }
                            else castlingFigure = nullptr;
                        }
                    }
                }
            }
        }
        if (selectFigure->getAvailableStep(newPosX, newPosY)) // если фигура может встать в эту клетку
        {
            if (board->getCellBoard(newPosX, newPosY) == "") // клетка свободна
            {
                // если это рокировка
                if (castlingFigure != nullptr)
                {
                    selectFigure->setPositionCell(newPosX, newPosY); // установка короля
                    board->setCellBoard(oldPosX, oldPosY, "");
                    board->setCellBoard(newPosX, newPosY, team);
                    if (castlingFigure->getXcell() == 0) // если длинная рокировка
                    {
                        castlingFigure->setPositionCell(newPosX+1, newPosY);
                        board->setCellBoard(newPosX-2, oldPosY, "");
                        board->setCellBoard(newPosX+1, newPosY, team);
                    }
                    if (castlingFigure->getXcell() == 7) // если короткая рокировка
                    {
                        castlingFigure->setPositionCell(newPosX-1, newPosY);
                        board->setCellBoard(newPosX+1, oldPosY, "");
                        board->setCellBoard(newPosX-1, newPosY, team);
                    }

                }
                else {
                    selectFigure->setPositionCell(newPosX, newPosY);
                    board->setCellBoard(oldPosX, oldPosY, "");
                    board->setCellBoard(newPosX, newPosY, team);
                }
                // переход хода
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
    // установка битых клеток для каждой команды
    setBeatCells(figures);
    // установка значений шахов королей
    figures.setWhiteCheck(getBlackBeat(whiteKing->getXcell(), whiteKing->getYcell()));
    figures.setBlackCheck(getWhiteBeat(blackKing->getXcell(), blackKing->getYcell()));

    // если был ход белых
    if (team == "White")
    {
        // и белые стали под шахом, то откатить ход
        if (figures.getWhiteCheck())
            rollback = true;
        else rollback = false;
    }
    // если был ход черных
    else if (team == "Black")
    {
        // и черные стали под шахом, то откатить ход
        if (figures.getBlackCheck())
            rollback = true;
        else rollback = false;
    }
    // откат хода
    if (rollback)
    {
        board->load(caretakerBoard->getBoardSave());
        figures.load(caretakerFigure->getFiguresSave());
        for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
        {
            (*iterFigure)->calcSteps();
        }
        setKings(figures);
    }



}

ControllerMove::ControllerMove(VectorOfFigures& figures)
{
    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        if ((*iterFigure)->getTeam() == "White" && (*iterFigure)->getType() == "King")
            whiteKing = (*iterFigure);
        if ((*iterFigure)->getTeam() == "Black" && (*iterFigure)->getType() == "King")
            blackKing = (*iterFigure);
    }
}

bool ControllerMove::getWhiteBeat(int x, int y)
{
    return whiteBeatCells[y][x];
}

bool ControllerMove::getBlackBeat(int x, int y)
{
    return blackBeatCells[y][x];
}

void ControllerMove::setBeatCells(VectorOfFigures &figures)
{
    for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
    {
        whiteBeatCells[i][j] = false;
        blackBeatCells[i][j] = false;
    }

    // просмотр всех фигур на доске
    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        QVector<QVector<bool> > beatCells = (*iterFigure)->getAllBeatCells();
        // текущая фигура принадлежит белой команде
        if ((*iterFigure)->getTeam() == "White")
        {
            for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if (beatCells[i][j])
                    whiteBeatCells[i][j] = beatCells[i][j];
            }
        }
        // текущая фигура принадлежит черной команде
        else
        {
            for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
            {
                if (beatCells[i][j])
                    blackBeatCells[i][j] = beatCells[i][j];
            }
        }
    }
//    qDebug() << "allBeat:";
//    for (int i = 0; i < 8; i++)
//      for (int j = 0; j < 8; j++)
//        qDebug() << "whiteBeatCells " << "[" << i << "]" << "[" << j << "]: " << whiteBeatCells[i][j];
    //    qDebug() << "\n";
}

void ControllerMove::setKings(VectorOfFigures &figures)
{
    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        if ((*iterFigure)->getTeam() == "White" && (*iterFigure)->getType() == "King")
            whiteKing = (*iterFigure);
        if ((*iterFigure)->getTeam() == "Black" && (*iterFigure)->getType() == "King")
            blackKing = (*iterFigure);
    }
}
