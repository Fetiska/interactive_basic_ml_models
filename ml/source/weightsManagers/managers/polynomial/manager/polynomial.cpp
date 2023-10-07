#include "polynomial.h"
#include "simple.h"
#include "setsManager.h"
#include "polynomialWeight.h"
#include "common.h"

void polynomial::updateParameters() {
	std::vector<float> errors{};//why: not create temp varaiables for new parameters + not caluate errors again when calcualte bias derivative sum

	size_t setsSize{ model.setsManager->getSets().size() };

	errors.reserve(setsSize);

	//calculate errors
	for (setsElementConstReference set : model.setsManager->getSets()) {
		errors.push_back(calculateError(set));
	}

	//update weights
	for (size_t weight{ 0 }; weight < weights.size(); ++weight) {
		float weightDerivativeSum{ 0 };

		//calculate weight derivative sum
		for (size_t set{ 0 }; set < setsSize; ++set) {
			weightDerivativeSum += errors[set] * pow(model.setsManager->getSets()[set]->input, static_cast<float>(dynamic_cast<polynomialWeight*>(weights[weight].get())->power));//weight + 1: weight variable starts from 0
		}

		float& currentWeight{ weights[weight]->value };
		updateParameter(currentWeight, weightDerivativeSum, model.regularizationParameter * currentWeight);
	}

	//update bias
	{
		float biasDerivativeSum{ 0 };

		//calculate bias derivative sum
		for (size_t set{ 0 }; set < setsSize; ++set) {
			biasDerivativeSum += errors[set];
		}

		updateParameter(model.bias, biasDerivativeSum, model.regularizationParameter * model.bias);
	}
}

void polynomial::drawCurve() const {
	sf::VertexArray curve(sf::LineStrip, common::xSize);

	for (size_t input{ 0 }; input < common::xSize - 1; ++input) {
		curve[input] = sf::Vector2f(static_cast<float>(input), common::denormalizeOutput(model.calculateHypothesis(common::xNormalize(input))));
		curve[input + 1] = sf::Vector2f(static_cast<float>(input + 1), common::denormalizeOutput(model.calculateHypothesis(common::xNormalize(input + 1))));
	}

	common::window.draw(curve);
}

float polynomial::calculateOutput(const float input) const {
	float output{ model.bias };

	for (size_t weight{ 0 }; weight < weights.size(); ++weight) {
		output += weights[weight]->value * pow(input, static_cast<float>(dynamic_cast<polynomialWeight*>(weights[weight].get())->power));//weight + 1: weight variable starts from 0
	}

	return output;
}

float polynomial::calculateRegularizationSum() const {
	float regularizationSum{ 0 };

	for (size_t weight{ 0 }; weight < weights.size(); ++weight) {
		regularizationSum += calculateRegularizationSumTerm(weights[weight]->value);
	}

	return regularizationSum;
}

float polynomial::calculateRegularizationTerm(const float parameter) const {
	return model.regularizationParameter * parameter;
}

void polynomial::onNewSet() {
	if (model.setsManager->getSets().size() > 1) {//why: number of weights must always be < number of points by 1
		weights.push_back(std::make_unique<polynomialWeight>(1.0f, static_cast<int>(model.setsManager->getSets().size() + 1)));
	}
}