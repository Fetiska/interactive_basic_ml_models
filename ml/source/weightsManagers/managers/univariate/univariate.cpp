#include "univariate.h"
#include "simple.h"
#include "setsManager.h"
#include "set.h"
#include "common.h"

void univariate::updateParameters() {
	float weightDerivativeSum{ 0 };
	float biasDerivativeSum{ 0 };

	//calculate derivatives sum
	for (setsElementConstReference set : model.setsManager->getSets()) {
		float error{ calculateError(set) };

		weightDerivativeSum += error * set->input;
		biasDerivativeSum += error;
	}

	updateParameter(weight, weightDerivativeSum);
	updateParameter(model.bias, biasDerivativeSum);
}

void univariate::drawCurve() const {
	const float x1{ 0 };
	sf::Vertex lineVertices[]{ sf::Vector2f(x1, common::denormalizeOutput(model.calculateHypothesis(x1))), sf::Vector2f(static_cast<float>(common::xSize), common::denormalizeOutput(model.calculateHypothesis(common::xNormalize(common::xSize)))) };
	common::window.draw(lineVertices, 2, sf::LineStrip);
}

float univariate::calculateOutput(const float input) const {
	return weight * input + model.bias;
}

float univariate::calculateRegularizationSum() const {
	return calculateRegularizationSumTerm(weight);
}
