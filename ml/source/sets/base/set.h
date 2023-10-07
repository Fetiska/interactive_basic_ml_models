#pragma once

#include "SFML/Graphics.hpp"

class set {
protected: set(const sf::Vector2i& position);
public:
	const sf::Vector2i position{};
	const float input{};

	virtual float getOutput() const = 0;
	virtual void setColor(sf::CircleShape& point) const;
};