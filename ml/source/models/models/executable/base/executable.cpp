#include "executable.h"
#include "common.h"
#include "setsManager.h"
#include "setsElementConstReference.h"

void executable::execute() {
	//event
	{
		while (common::window.pollEvent(common::event)) {
			//close window
			if (common::event.type == sf::Event::Closed) {
				common::window.close();
				return;
			}

			//close window if escape pressed
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				common::window.close();
				return;
			}

			//add point
			if (common::event.type == sf::Event::MouseButtonReleased) {
				setsManager->tryAddSet(sf::Mouse::getPosition());
			}
		}
	}

	common::window.clear();

	const std::vector<std::unique_ptr<set>>& sets {setsManager->getSets()};

	if (sets.size() > 0) {
		//draw points
		for (setsElementConstReference set : sets) {
			float radius = common::ySize * 0.003f;//0.3% of screen height
			sf::CircleShape point(radius);
			point.setOrigin(radius, radius);
			point.setPosition(sf::Vector2f(set->position));
			set->setColor(point);

			common::window.draw(point);
		}

		learn();
		drawCurve();

		common::print("cost " + std::to_string(setsManager->calculateCost()), common::textSize);
	}
}