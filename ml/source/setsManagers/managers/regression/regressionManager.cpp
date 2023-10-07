#include "regressionManager.h"
#include "common.h"
#include "regressionSet.h"
#include "weightsManager.h"
#include "setsElementConstReference.h"
#include "simple.h"

void regressionManager::tryAddSet(const sf::Vector2i& position) {
	if (common::event.mouseButton.button == sf::Mouse::Left) {
		addSet(std::make_unique<regressionSet>(position));
	}
}
float regressionManager::calculateCostFunctionDerivative() const {
	float sum{ 0 };

	//squared error sum
	for (setsElementConstReference set : getSets()) {
		sum += pow(calculateHypothesis(set->input) - set->getOutput(), 2.f);
	}

	return sum;
}
