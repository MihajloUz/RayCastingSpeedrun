#pragma once
#include "includes.h"
struct Beams {
	Beams() {
		for (int i = 0; i < amountOfSlices; ++i) {
			distances.push_back(0);
		}
	}
	std::vector<float> distancer() {
		float startingAngle = angle - (fov / 2);
		float angleStep = fov / distances.size();
		float step = 0.01f;
		for (int i = 0; i < distances.size(); ++i) {
			distances[i] = 0;
			bool hitTheWall = false;
			sf::Vector2f startingPosition = playerPosition;
			startingAngle += angleStep;
			while (distances[i] < maxDistance && !hitTheWall) {
				startingPosition += {step * cos(radians(startingAngle)), step * sin(radians(startingAngle))};
				if (map[floor(startingPosition.y)][floor(startingPosition.x)])
					hitTheWall = true;
				distances[i] += step;
			}
			
		}
		return distances;
	}
private:
	std::vector<float> distances;
};