#pragma once

#include "set.h"

class regressionSet : public set {
	const float output{};
public:
	float getOutput() const override;

	regressionSet(const sf::Vector2i& position);
};