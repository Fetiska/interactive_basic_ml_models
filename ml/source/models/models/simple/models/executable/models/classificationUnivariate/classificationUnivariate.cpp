#include "classificationUnivariate.h"
#include "setsManagers/managers/classification/classificationManager.h"
#include "weightsManagers/managers/univariate/univariate.h"

classificationUnivariate::classificationUnivariate() {
	setsManager = std::make_unique<classificationManager>(*this);
	weightsManager = std::make_unique<univariate>(*this);
}
float classificationUnivariate::calculateHypothesis(const float input) const {
	return 1 / (1 + pow(2.718281f, -weightsManager->calculateOutput(input)));
}