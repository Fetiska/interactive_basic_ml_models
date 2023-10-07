#pragma once

#include "weightsManager.h"

class univariate : public weightsManager {
public:
	float weight{1.0f};

	using weightsManager::weightsManager;

	void updateParameters() override;
	void drawCurve() const override;
	float calculateOutput(const float input) const override;
	float calculateRegularizationSum() const override;
};