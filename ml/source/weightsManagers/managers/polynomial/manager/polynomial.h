#pragma once

#include "weightsManager.h"
#include "polynomialWeight.h"//why not forward declare polynomialWeight: doesn't work because smart pointer used in vector

class polynomial : public weightsManager {
private: std::vector<std::unique_ptr<polynomialWeight>> weights{};
public:
	using weightsManager::weightsManager;

	void updateParameters();
	void drawCurve() const override;
	float calculateOutput(const float input) const override;
	void onNewSet() override;
	float calculateRegularizationSum() const override;
	float calculateRegularizationTerm(const float parameter) const override;
};