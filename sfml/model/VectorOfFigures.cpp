#include "VectorOfFigures.h"

VectorOfFigures::VectorOfFigures()
{
    /// белые фигуры
    allFigures.emplace_back( std::shared_ptr<Rook>(new Rook(QString("White"), 63, 511)) );
    allFigures.emplace_back( std::shared_ptr<Knight>(new Knight(QString("White"), 127, 511)) );
    allFigures.emplace_back( std::shared_ptr<Bishop>(new Bishop(QString("White"), 191, 511)) );
    allFigures.emplace_back( std::shared_ptr<Queen>(new Queen(QString("White"), 255, 511)) );
    allFigures.emplace_back( std::shared_ptr<King>(new King(QString("White"), 319, 511)) );
    allFigures.emplace_back( std::shared_ptr<Bishop>(new Bishop(QString("White"), 383, 511)) );
    allFigures.emplace_back( std::shared_ptr<Knight>(new Knight(QString("White"), 447, 511)) );
    allFigures.emplace_back( std::shared_ptr<Rook>(new Rook(QString("White"), 511, 511)) );
    // пешки
    for (int i = 0, posX = 63; i < 8; i++, posX += 64)
        allFigures.emplace_back( std::shared_ptr<Pawn>(new Pawn(QString("White"), posX, 447)) );

    /// черные фигуры
    allFigures.emplace_back( std::shared_ptr<Rook>(new Rook(QString("Black"), 63, 63)) );
    allFigures.emplace_back( std::shared_ptr<Knight>(new Knight(QString("Black"), 127, 63)) );
    allFigures.emplace_back( std::shared_ptr<Bishop>(new Bishop(QString("Black"), 191, 63)) );
    allFigures.emplace_back( std::shared_ptr<Queen>(new Queen(QString("Black"), 255, 63)) );
    allFigures.emplace_back( std::shared_ptr<King>(new King(QString("Black"), 319, 63)) );
    allFigures.emplace_back( std::shared_ptr<Bishop>(new Bishop(QString("Black"), 383, 63)) );
    allFigures.emplace_back( std::shared_ptr<Knight>(new Knight(QString("Black"), 447, 63)) );
    allFigures.emplace_back( std::shared_ptr<Rook>(new Rook(QString("Black"), 511, 63)) );
    // пешки
    for (int i = 0, posX = 63; i < 8; i++, posX += 64)
        allFigures.emplace_back( std::shared_ptr<Pawn>(new Pawn(QString("Black"), posX, 127)) );

    for (auto iterFigure = allFigures.begin(); iterFigure != allFigures.end(); ++iterFigure)
    {
        (*iterFigure)->calcSteps();
    }

    currentStep = "White";
}

//void VectorOfFigures::create()
//{
//    /// белые фигуры
//    allFigures.push_back( new Rook(QString("White"), 63, 511) );
//    allFigures.push_back( new Knight(QString("White"), 127, 511) );
//    allFigures.push_back( new Bishop(QString("White"), 191, 511) );
//    allFigures.push_back( new Queen(QString("White"), 255, 511) );
//    allFigures.push_back( new King(QString("White"), 319, 511) );
//    allFigures.push_back( new Bishop(QString("White"), 383, 511) );
//    allFigures.push_back( new Knight(QString("White"), 447, 511) );
//    allFigures.push_back( new Rook(QString("White"), 511, 511) );
//    // пешки
//    for (int i = 0, posX = 63; i < 8; i++, posX += 64)
//        allFigures.push_back( new Pawn(QString("White"), posX, 447));

//    /// черные фигуры
//    allFigures.push_back( new Rook(QString("Black"), 63, 63) );
//    allFigures.push_back( new Knight(QString("Black"), 127, 63) );
//    allFigures.push_back( new Bishop(QString("Black"), 191, 63) );
//    allFigures.push_back( new Queen(QString("Black"), 255, 63) );
//    allFigures.push_back( new King(QString("Black"), 319, 63) );
//    allFigures.push_back( new Bishop(QString("Black"), 383, 63) );
//    allFigures.push_back( new Knight(QString("Black"), 447, 63) );
//    allFigures.push_back( new Rook(QString("Black"), 511, 63) );
//    // пешки
//    for (int i = 0, posX = 63; i < 8; i++, posX += 64)
//        allFigures.push_back(new Pawn(QString("Black"), posX, 127));
//}

//QList<Figure*> ListOfFigures::getAllFigures()
//std::vector<Figure*> VectorOfFigures::getAllFigures()
std::vector<std::shared_ptr<Figure> > &VectorOfFigures::getAllFigures()
{
    return allFigures;
}

void VectorOfFigures::replaceBack(int currentPosition)
{
    std::swap(allFigures.at(currentPosition), allFigures.at(allFigures.size()-1));
   // std::rotate(allFigures.begin(), allFigures.begin()+currentPosition, allFigures.rbegin()+currentPosition);
    //allFigures.move(currentPosition, allFigures.size()-1);
}

QString VectorOfFigures::getCurrentStep()
{
    return currentStep;
}

void VectorOfFigures::setCurrentStep(QString curStep)
{
    currentStep = curStep;
}

std::shared_ptr<MementoFigures> VectorOfFigures::save()
{
    size_t size = allFigures.size();
    std::vector< std::shared_ptr<Figure> > copyVector;

    for (size_t i = 0; i < size; i++)
    {
        copyVector.emplace_back(allFigures[i]->clone());
    }

    return std::shared_ptr<MementoFigures>(new MementoFigures(copyVector, currentStep));
}

void VectorOfFigures::load(const std::shared_ptr<MementoFigures> figuresSave)
{
    std::vector< std::shared_ptr<Figure> > tmpVec = figuresSave->getFigures();

    allFigures.swap(tmpVec);
    currentStep = figuresSave->getCurrentStep();
}
