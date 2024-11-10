#include <SFML/Graphics.hpp>
#include <Observer.h>
#include <Eigen/Core>

int main() {
	sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
		
		window.clear();

		// render

		window.display();
	}

	return 0;
}
