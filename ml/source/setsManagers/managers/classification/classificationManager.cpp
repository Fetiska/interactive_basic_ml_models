#include "classificationManager.h"
#include "common.h"
#include "classificationSet.h"
#include "weightsManager.h"
#include "setsElementConstReference.h"
#include "simple.h"

void classificationManager::tryAddSet(const sf::Vector2i& position) {
	if (common::event.mouseButton.button == sf::Mouse::Left) {
		addSet(std::make_unique<classificationSet>(position, false, sf::Color{179, 255, 0, 255}));//green
	}
	else {
		addSet(std::make_unique<classificationSet>(position, true, sf::Color{185, 0, 255, 255}));//purple
	}
}

float classificationManager::calculateCostFunctionDerivative() const {
	float sum{ 0 };

	//logistic loss sum
	for (setsElementConstReference set : getSets()) {
		if (set->getOutput() == 1.f) {
			sum += -log(calculateHypothesis(set->input));
		}
		else {
			sum += -log(1 - calculateHypothesis(set->input));
		}
	}

	return sum;
}
