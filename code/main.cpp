#include "includes.h"
#include "beam.h"
#include "wall.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(screenSize.x, screenSize.y), "raycasting", sf::Style::Close);
	
	sf::Event event;
	window.setFramerateLimit(60);
	
	Beams beams;
	Wall wall;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return 0;
			}
		}
		playerMovement();
		wall.sizing_coloring(beams.distancer());
		
		window.clear();
		
		wall.draw(window);
		
		window.display();
	}
	return 0;
}