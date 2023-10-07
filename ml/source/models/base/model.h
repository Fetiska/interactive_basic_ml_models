#pragma once

#include <memory>

class setsManager;

class model {
protected: virtual void learn() = 0;
public:
	const float learningRate{ .9f };
	const float regularizationParameter{ .00001f };
	std::unique_ptr<setsManager> setsManager{};

	virtual ~model();//why: forward declare setsManager used for std::unique_ptr
};