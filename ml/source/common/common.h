#pragma once

#include <SFML/Graphics.hpp>

class common {
public:
	inline static sf::RenderWindow window{sf::VideoMode::getDesktopMode(), "ml", sf::Style::Fullscreen};
	inline static sf::Event event;

	inline static const unsigned int ySize{ window.getSize().y };
	inline static const unsigned int xSize{ window.getSize().x };
	inline static sf::Font font;
	inline static const unsigned int textSize{ static_cast<unsigned int>(ySize * 0.02f) };//2% of screen height

	static float xNormalize(const unsigned int xPosition);
	static float denormalizeOutput(const float output);
	static void print(const std::string text, const unsigned int yPosition = .0f);
};