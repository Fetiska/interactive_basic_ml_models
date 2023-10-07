#pragma once

#include "setsElementConstReference.h"

class simple;

class weightsManager {
protected:
	simple& model;

	float calculateError(setsElementConstReference set) const;
	void updateParameter(float& parameter, const float derivativeSum, const float regularizationTerm = 0);
	float calculateRegularizationSumTerm(const float weight) const;
	virtual float calculateRegularizationTerm(const float parameter) const;
public:
	weightsManager(class::simple& model);

	virtual void updateParameters() = 0;
	virtual void drawCurve() const = 0;
	virtual float calculateOutput(const float input) const = 0;
	virtual float calculateRegularizationSum() const = 0;
	virtual void onNewSet();
};