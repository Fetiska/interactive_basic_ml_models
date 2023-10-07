#pragma once

#include "model.h"

class executable : virtual  public model {
private: virtual void drawCurve() = 0;
public: void execute();
};