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
    std::shared_ptr<Figure> castlingFigure = nullptr;
    std::shared_ptr<Figure> whiteKing;
    std::shared_ptr<Figure> blackKing;
    std::shared_ptr<Figure> pawnEnPassant; // пешка, которую берут на проходе
    //bool enPassant = false;
    int enPassantX;
    int enPassantY;
    //QPointer<Figure*> selectFigure;
    sf::Vector2i cursorPos; // координаты курсора мыши
    int cursorCellX;
    int cursorCellY;
    void takeFigure(VectorOfFigures& figures);
    bool rollback;

    bool whiteBeatCells[8][8];
    bool blackBeatCells[8][8];
public:
    bool getWhiteBeat(int x, int y);
    bool getBlackBeat(int x, int y);
    void setBeatCells(VectorOfFigures& figures);
    void enPassant(QString &team, VectorOfFigures& figures); // проверка на взятие на проходе

    ControllerMove(VectorOfFigures& figures);
    void setKings(VectorOfFigures& figures);
    void checkSelect(sf::Event& event, sf::RenderWindow& window, VectorOfFigures& figures);
    void moving();

};

#endif // CONTROLLERMOVE_H
