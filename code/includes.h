#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <execution>
#include <ranges>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>

float radians(float degreese) {
	return (degreese * (3.14 / 180));
}

std::vector<std::vector<int>> map = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
sf::Vector2f playerPosition = { 2, 2 };
float fov = 90.f;
float angle = 90.f;
float speed = 0.05f;
sf::Vector2f direction = {cos(radians(angle)), sin(radians(angle))};
sf::Vector2f screenSize = { 1280, 720 };
int amountOfSlices = 320;
sf::Vector2f sliceSize = {screenSize.x / amountOfSlices, 100};
float maxDistance = 5.f;

void playerMovement() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		angle -= 5.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		angle += 5.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerPosition.x += speed * cos(radians(angle));
		playerPosition.y += speed * sin(radians(angle));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerPosition.x -= speed * cos(radians(angle));
		playerPosition.y -= speed * sin(radians(angle));
	}
}
float sigmoid(float x) {
	return 1.f / 1.f + exp(-x);
}