#pragma once

#include "setsManagers/base/setsManager.h"

class classificationManager : public setsManager {
	using setsManager::setsManager;

	void tryAddSet(const sf::Vector2i& position) override;
	float calculateCostFunctionDerivative() const override;
};