#include "setsManager.h"
#include "simple.h"
#include "setsElementConstReference.h"
#include "weightsManager.h"

setsManager::setsManager(const simple& model) : model{ model } {}

float setsManager::calculateCost() const {
	return (calculateCostFunctionDerivative() + model.regularizationParameter * model.weightsManager->calculateRegularizationSum()) / sets.size();
}

void setsManager::addSet(std::unique_ptr<set> set) {
	sets.push_back(std::move(set));
	model.weightsManager->onNewSet();
}

const std::vector<std::unique_ptr<set>>& setsManager::getSets() const {
	return sets;
}

float setsManager::calculateHypothesis(const float input) const {
	return model.calculateHypothesis(input);
}
