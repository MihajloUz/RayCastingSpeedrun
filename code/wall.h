#pragma once
#include "includes.h"
struct Wall {
	Wall() {
		for (int i = 0; i < amountOfSlices; ++i) {
			sf::RectangleShape bufferRect;
			bufferRect.setPosition(sf::Vector2f(i * sliceSize.x, screenSize.y / 2));
			slice.push_back(bufferRect);
		}
	}
	void sizing_coloring(std::vector<float> distances) {
		for (int i = 0; i < amountOfSlices; ++i) {
			float height = (distances[i] > 0.01f) ? (500.f / distances[i]) : 500.f;
			slice[i].setSize({ screenSize.x / amountOfSlices, height });
			slice[i].setOrigin(0, height / 2); 
			slice[i].setPosition(i * sliceSize.x, screenSize.y / 2);
			sf::Uint8 shade = static_cast<sf::Uint8>((distances[i] < maxDistance) ? (sigmoid(distances[i]) * 255) : 0);
			slice[i].setFillColor(sf::Color(shade, shade, shade));
		}
	}
	virtual void draw(sf::RenderWindow& window) {
		for (int i = 0; i < amountOfSlices; ++i) {
			window.draw(slice[i]);
		}
	}

private:
	std::vector<sf::RectangleShape> slice;
};