#include <iostream>
#include <SFML/Graphics.hpp>

#include "Ship.hpp"

int main() {
	sf::RenderWindow	win(sf::VideoMode(1920, 1080), "R-Type");
	Ship			ship;

	while (win.isOpen())
	{
		// Process events
		sf::Event event;
		while (win.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				win.close();
		}
		// Clear screen
		win.clear();

		ship.update(event);
		//Display Ship Sprite
		win.draw(ship);
		// Update the window
		win.display();
	}
	return 0;
}