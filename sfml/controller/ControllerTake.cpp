#include "ControllerTake.h"
#include <QDebug>
ControllerTake::ControllerTake()
{

}

void ControllerTake::takeFigure(VectorOfFigures& figures)
{
    int oldPosX = figures.getAllFigures()[figures.getAllFigures().size()-1]->getOldXcell();
    int oldPosY = figures.getAllFigures()[figures.getAllFigures().size()-1]->getOldYcell();
    int newPosX = figures.getAllFigures()[figures.getAllFigures().size()-1]->getXcell();
    int newPosY = figures.getAllFigures()[figures.getAllFigures().size()-1]->getYcell();

    if ( (oldPosX != newPosX) && (oldPosY != newPosY) ) // фигура была передвинута
    {
        qDebug() << newPosX << "   " << newPosY << "  |  " << oldPosX << "  " << oldPosY;
        for (size_t iterFigure = 0; iterFigure < figures.getAllFigures().size(); iterFigure++)
        {
            int takenX = figures.getAllFigures()[iterFigure]->getXcell();
            int takenY = figures.getAllFigures()[iterFigure]->getYcell();
            if ( (newPosX == takenX) && (newPosY == takenY) ) // фигуры оказались на одной клетке
            {
                if ( figures.getAllFigures()[figures.getAllFigures().size()-1]->getTeam() != figures.getAllFigures()[iterFigure]->getTeam() )  // фигуры разного цвета
                {
                    figures.getAllFigures().erase(figures.getAllFigures().begin()+iterFigure); // удалить фигуру iterFigure
                }
                else // фигуры одного цвета
                {
                    //figures.getAllFigures()[figures.getAllFigures().size()-1]->setPositionCell(oldPosX, oldPosY);
                    break;
                }
            }
        }
    }
}
