#include "CaretakerBoard.h"

CaretakerBoard* CaretakerBoard::_instance = 0;

CaretakerBoard *CaretakerBoard::Instance()
{
    if (_instance == 0)
        _instance = new CaretakerBoard();
    return _instance;
}

std::shared_ptr<MementoBoard> CaretakerBoard::getBoardSave()
{
    return boardSave;
}

void CaretakerBoard::setBoardSave(std::shared_ptr<MementoBoard> board)
{
    this->boardSave = board;
}
