#include "regressionPolynomial.h"
#include "regressionManager.h"
#include "polynomial.h"

regressionPolynomial::regressionPolynomial() {
	setsManager = std::make_unique<regressionManager>(*this);
	weightsManager = std::make_unique<polynomial>(*this);
}

float regressionPolynomial::calculateHypothesis(const float input) const {
	return weightsManager->calculateOutput(input);
}
