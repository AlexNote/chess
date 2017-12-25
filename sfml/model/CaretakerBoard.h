#ifndef CARETAKERBOARD_H
#define CARETAKERBOARD_H

#include "MementoBoard.h"
#include <memory>

class CaretakerBoard
{
private:
    CaretakerBoard() = default;
    ~CaretakerBoard() = default;
    CaretakerBoard(const CaretakerBoard&) = delete;
    CaretakerBoard& operator=(const CaretakerBoard&) = delete;
    static CaretakerBoard* _instance;

    std::shared_ptr<MementoBoard> boardSave;

public:
    static CaretakerBoard* Instance();

    std::shared_ptr<MementoBoard> getBoardSave();
    void setBoardSave(std::shared_ptr<MementoBoard> board);
};

#endif // CARETAKERBOARD_H
