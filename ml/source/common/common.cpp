#include "common/common.h"

float common::xNormalize(const unsigned int xPosition) {
	return static_cast<float>(xPosition) / xSize;
}

float common::denormalizeOutput(const float output) {
	return output * common::ySize;
}

void common::print(const std::string text, const unsigned int yPosition) {
	sf::Font font;
	font.loadFromFile("source/font.ttf");

	sf::Text displayText{text, font, textSize};
	displayText.setPosition(.0f, yPosition);

	window.draw(displayText);
}