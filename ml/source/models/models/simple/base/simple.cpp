#include "simple.h"
#include "weightsManager.h"

simple::~simple() {};
void simple::learn() { weightsManager->updateParameters(); }