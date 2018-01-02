#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <QString>
#include <QVector>
#include <memory>
#include "MementoBoard.h"

class Board {
public:
    static Board* Instance();
    sf::Sprite getBoard();
    QString getCellBoard(int x, int y);
    void setCellBoard(int x, int y, QString team);

    void load(std::shared_ptr<MementoBoard> boardSave);
    std::shared_ptr<MementoBoard> save();

private:
    Board() = default;
    ~Board() = default;
    Board(const Board&) = delete;
    Board& operator=(const Board&) = delete;

    static Board* _instance;
    sf::Texture textureBoard;
    sf::Sprite spriteBoard;
    QVector< QVector< QString > > board = {
        {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
        {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
        {"",      "",      "",      "",      "",      "",      "",      ""     },
        {"",      "",      "",      "",      "",      "",      "",      ""     },
        {"",      "",      "",      "",      "",      "",      "",      ""     },
        {"",      "",      "",      "",      "",      "",      "",      ""     },
        {"White", "White", "White", "White", "White", "White", "White", "White"},
        {"White", "White", "White", "White", "White", "White", "White", "White"}
    };
//    QString board[8][8] = {
//        {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
//        {"Black", "Black", "Black", "Black", "Black", "Black", "Black", "Black"},
//        {"",      "",      "",      "",      "",      "",      "",      ""     },
//        {"",      "",      "",      "",      "",      "",      "",      ""     },
//        {"",      "",      "",      "",      "",      "",      "",      ""     },
//        {"",      "",      "",      "",      "",      "",      "",      ""     },
//        {"White", "White", "White", "White", "White", "White", "White", "White"},
//        {"White", "White", "White", "White", "White", "White", "White", "White"} };
};



//sf::String board[SIZE] = { // игровое поле
//	"0000000000",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0ffffffff0",
//	"0000000000"
//};

#endif // BOARD_H
