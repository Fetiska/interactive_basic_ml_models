#pragma once

#include "executableSimple.h"

class classificationUnivariate : public executableSimple {
public:
	classificationUnivariate();
	float calculateHypothesis(const float input) const override;
};