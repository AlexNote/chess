#ifndef VECTOROFFIGURES_H
#define VECTOROFFIGURES_H

//#include <QList>
#include <vector>
#include <QString>
#include "figure/Rook.h"
#include "figure/Knight.h"
#include "figure/Bishop.h"
#include "figure/Queen.h"
#include "figure/King.h"
#include "figure/Pawn.h"
#include <memory>
#include "MementoFigures.h"

class VectorOfFigures
{
private:
    //QList<Figure*> allFigures;
    //std::vector<Figure*> allFigures;
    std::vector< std::shared_ptr<Figure> > allFigures;
    QString currentStep; // какая команда делает текущий ход
    bool whiteBeatCells[8][8];
    bool blackBeatCells[8][8];
public:
    VectorOfFigures();
    //void create();
    //QList<Figure*> getAllFigures();
    //std::vector<Figure*> getAllFigures();
    std::vector< std::shared_ptr<Figure> >& getAllFigures();
    void replaceBack(int currentPosition);
    QString getCurrentStep();
    void setCurrentStep(QString curStep);

    std::shared_ptr<MementoFigures> save();
    void load(const std::shared_ptr<MementoFigures> figuresSave);


    bool getWhiteBeat(int x, int y);
    bool getBlackBeat(int x, int y);
    void setBeatCells();
};

#endif // VECTOROFFIGURES_H
