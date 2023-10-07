#include "classificationSet.h"
#include "common.h"

classificationSet::classificationSet(const sf::Vector2i& position, const bool output, const sf::Color& color) : set(position), output{ output }, color{ color } {}

float classificationSet::getOutput() const { return output; }

void classificationSet::setColor(sf::CircleShape& point) const {
	point.setFillColor(color);
}