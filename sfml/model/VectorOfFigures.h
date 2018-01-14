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
    bool whiteCheck;
    bool blackCheck;
    int countSteps;

    sf::Texture textureChangeFigures;
    sf::Sprite whiteSpriteChange;
    sf::Sprite blackSpriteChange;
public:
    VectorOfFigures();
    //void create();
    //QList<Figure*> getAllFigures();
    //std::vector<Figure*> getAllFigures();
    void incCountSteps();
    int getCountSteps();
    std::vector< std::shared_ptr<Figure> >& getAllFigures();
    void replaceBack(int currentPosition);
    QString getCurrentStep();
    void setCurrentStep(QString curStep);

    sf::Sprite getChahgeWhite();
    sf::Sprite getChahgeBlack();

    void setWhiteCheck(bool state);
    void setBlackCheck(bool state);
    bool getWhiteCheck();
    bool getBlackCheck();

    std::shared_ptr<MementoFigures> save();
    void load(const std::shared_ptr<MementoFigures> figuresSave);
};

#endif // VECTOROFFIGURES_H
