#include "classificationPolynomial.h"
#include "classificationManager.h"
#include "polynomial.h"

classificationPolynomial::classificationPolynomial() {
	setsManager = std::make_unique<classificationManager>(*this);
	weightsManager = std::make_unique<polynomial>(*this);
}
float classificationPolynomial::calculateHypothesis(const float input) const {
	return 1 / (1 + pow(2.718281f, -weightsManager->calculateOutput(input)));
}