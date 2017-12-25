#include "ViewPlay.h"

void ViewPlay::playGame(sf::RenderWindow& window, VectorOfFigures &figures)
{

    for (auto iterFigure = figures.getAllFigures().begin(); iterFigure != figures.getAllFigures().end(); ++iterFigure)
    {
        window.draw((*iterFigure)->getFigure());
    }

//    for (int i = 0; i < figures.size(); ++i)
//    {
//        window.draw(figures[i]->getFigure());

//    }

//    for (auto fig : figures)
//    {
//        fig->getFigure();
//    }
    //figures[0]->getFigure();


    //отрисовать все фгуры на стартовый позициях

}
