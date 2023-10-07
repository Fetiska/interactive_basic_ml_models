#pragma once

#include "setsManager.h"

class regressionManager : public setsManager {
	using setsManager::setsManager;

	void tryAddSet(const sf::Vector2i& position) override;
	float calculateCostFunctionDerivative() const override;
};