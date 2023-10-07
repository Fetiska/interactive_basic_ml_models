#pragma once

#include "executableSimple.h"

class regressionUnivariate : public executableSimple {
public:
	regressionUnivariate();
	float calculateHypothesis(const float input) const override;
};