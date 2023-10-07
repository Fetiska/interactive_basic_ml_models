#pragma once

#include "model.h"
#include <memory>

class weightsManager;

class simple : virtual public model {
private: void learn() override;
public:
	const float learningRate{ .9f };
	float bias{ 0 };
	float regularizationParameter{ .00001f };
	std::unique_ptr<weightsManager> weightsManager{};

	~simple();//why: forward declare weightsManager used for std::unique_ptr
	virtual float calculateHypothesis(const float input) const = 0;
};