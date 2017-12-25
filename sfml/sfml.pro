#-------------------------------------------------
#
# Project created by QtCreator 2017-09-24T23:37:49
#
#-------------------------------------------------

QT       += core gui
CONFIG += console c++11
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -L"C:/libs/SFML-2.4.2-build/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:/libs/SFML-2.4.2/include
DEPENDPATH += C:/libs/SFML-2.4.2/include

TARGET = sfml
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    model/figure/King.cpp \
    model/figure/Figure.cpp \
    model/Board.cpp \
    model/figure/Queen.cpp \
    model/figure/Rook.cpp \
    model/figure/Bishop.cpp \
    model/figure/Knight.cpp \
    model/figure/Pawn.cpp \
    controller/ControllerMove.cpp \
    view/ViewPlay.cpp \
    view/ViewStart.cpp \
    model/BtnStart.cpp \
    controller/ControllerStart.cpp \
    model/VectorOfFigures.cpp \
    controller/ControllerTake.cpp \
    model/MementoFigures.cpp \
    model/MementoBoard.cpp \
    model/CaretakerBoard.cpp \
    model/CaretakerFigure.cpp

HEADERS += \
    model/figure/King.h \
    model/figure/Figure.h \
    model/Board.h \
    model/figure/Queen.h \
    model/figure/Rook.h \
    model/figure/Bishop.h \
    model/figure/Knight.h \
    model/figure/Pawn.h \
    controller/ControllerMove.h \
    view/ViewPlay.h \
    view/ViewStart.h \
    model/BtnStart.h \
    controller/ControllerStart.h \
    model/VectorOfFigures.h \
    controller/ControllerTake.h \
    model/MementoFigures.h \
    model/MementoBoard.h \
    model/CaretakerBoard.h \
    model/CaretakerFigure.h
