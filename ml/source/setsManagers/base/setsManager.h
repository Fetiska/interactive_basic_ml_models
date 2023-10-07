#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "set.h"//why not forward declare polynomialWeight: doesn't work because smart pointer used in vector

class simple;

class setsManager {
	std::vector<std::unique_ptr<set>> sets;
	const simple& model;

	virtual float calculateCostFunctionDerivative() const = 0;
public:
	setsManager(const simple& model);

	virtual void tryAddSet(const sf::Vector2i& position) = 0;
	void addSet(std::unique_ptr<set> set);
	const std::vector<std::unique_ptr<set>>& getSets() const;
	float calculateHypothesis(const float input) const;
	float calculateCost() const;
};