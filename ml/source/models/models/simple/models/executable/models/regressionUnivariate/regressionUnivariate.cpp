#include "regressionUnivariate.h"
#include "regressionManager.h"
#include "univariate.h"

regressionUnivariate::regressionUnivariate() {
	setsManager = std::make_unique<regressionManager>(*this);
	weightsManager = std::make_unique<univariate>(*this);
}

float regressionUnivariate::calculateHypothesis(const float input) const {
	return weightsManager->calculateOutput(input);
}