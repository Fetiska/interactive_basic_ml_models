#include "set.h"
#include "common.h"

set::set(const sf::Vector2i& position) : position{ position }, input{ common::xNormalize(position.x) } {}

void set::setColor(sf::CircleShape& point) const {}//why empty: point has default color when constructed