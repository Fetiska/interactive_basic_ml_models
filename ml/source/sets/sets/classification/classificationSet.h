#pragma once

#include "set.h"

class classificationSet : public set {
	const bool output{};
	const sf::Color color{};//why: not use if statement in setColor

	float getOutput() const override;
	virtual void setColor(sf::CircleShape& point) const override;
public: classificationSet(const sf::Vector2i& position, const bool output, const sf::Color& color);
};