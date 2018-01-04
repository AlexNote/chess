#ifndef FIGURE_H
#define FIGURE_H

#include <QString>
#include <QVector>
#include <SFML/Graphics.hpp>
#include <memory>
#include "../Board.h"

/*
ранг фигур:
1 - король
2 - королева
3 - ладья
4 - конь
5 - слон
6 - пешка
*/

class Figure {
public:
    Figure();
    Figure(const Figure&);
    virtual std::shared_ptr<Figure> clone() const = 0;
    //std::shared_ptr<Figure> clone() const;
    sf::Sprite getFigure();
    void setPositionPixel(int x, int y);
    void setPositionCell(); // установка игровой позиции по позиции курсора
    void setPositionCell(int cellX, int cellY); // установка игровой позиции по позиции курсора
    void setOldPositionCell();
    void setCells(int x, int y); // установка игровой позиции по отношению к кординатам фигуры
    sf::Vector2f getPosition();
    int getXcell();
    int getYcell();
    int getOldXcell();
    int getOldYcell();
    QString getTeam();
    virtual void calcSteps() = 0;
    bool getAvailableStep(int x, int y);
    QVector< QVector<bool> > getAllSteps();
    virtual QVector< QVector<bool> > getAllBeatCells() = 0;
protected:
    int coordXpx;
    int coordYpx;
    int coordXcell;
    int coordYcell;
    int oldCoordXcell;
    int oldCoordYcell;
    QVector< QVector<bool> > availableSteps = {
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false}
    };
    QVector< QVector<bool> > allBeatCells = {
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false},
        {false, false, false, false,  false,  false,  false,  false}
    };
    QString team;
    sf::Texture textureFigure;
    sf::Sprite spriteFigure;

};

#endif // FIGURE_H
