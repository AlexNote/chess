#ifndef CONTROLLERTAKE_H
#define CONTROLLERTAKE_H

#include <SFML/Graphics.hpp>
#include "../model/VectorOfFigures.h"

class ControllerTake
{
public:
    ControllerTake();
    void takeFigure(VectorOfFigures& figures);
};

#endif // CONTROLLERTAKE_H
