#pragma once

#include "executableSimple.h"

class regressionPolynomial : public executableSimple {
public:
	regressionPolynomial();
	float calculateHypothesis(const float input) const override;
};