#include "weightsManager.h"
#include "simple.h"
#include "setsManager.h"
#include "setsElementConstReference.h"
#include "set.h"

weightsManager::weightsManager(class::simple& model) : model{ model } {}

float weightsManager::calculateError(setsElementConstReference set) const {
	return model.calculateHypothesis(set->input) - set->getOutput();
}

void weightsManager::updateParameter(float& parameter, const float derivativeSum, const float regularizationTerm) {
	parameter -= (model.learningRate * derivativeSum + calculateRegularizationTerm(parameter)) / model.setsManager->getSets().size();
}

float weightsManager::calculateRegularizationSumTerm(const float weight) const {
	return weight * weight;
}

float weightsManager::calculateRegularizationTerm(const float parameter) const {
	return 0.0f;
}

void weightsManager::onNewSet() {}