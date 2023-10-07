#include "regressionSet.h"
#include "common.h"

regressionSet::regressionSet(const sf::Vector2i& position) : set(position), output{ static_cast<float>(position.y) / common::ySize } {}

float regressionSet::getOutput() const { return output; }