#pragma once

#include "executableSimple.h"

class classificationPolynomial : public executableSimple {
public:
	classificationPolynomial();
	float calculateHypothesis(const float input) const override;
};