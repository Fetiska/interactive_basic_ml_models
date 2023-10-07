#include "classificationPolynomial.h"
#include "classificationUnivariate.h"
#include "common.h"
#include "regressionPolynomial.h"
#include "regressionUnivariate.h"

int main() {
	regressionPolynomial model{};

	sf::Clock clock;
	while (common::window.isOpen()) {
		clock.restart();

		model.execute();

		common::print("fps " + std::to_string(1.f / clock.getElapsedTime().asSeconds()));
		common::window.display();
	}
}