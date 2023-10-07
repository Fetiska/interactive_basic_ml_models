#pragma once

#include "simple.h"
#include "executable.h"

class executableSimple : public simple, public executable {
private: void drawCurve() override;
};