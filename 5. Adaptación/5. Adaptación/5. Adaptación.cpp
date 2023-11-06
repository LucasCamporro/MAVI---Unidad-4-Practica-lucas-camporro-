#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"ventana");

	Vector2u maxSize(1000, 1000);
	Vector2u minSize(400, 400);

	while (App.isOpen())
	{

		Event evnt;

		while (App.pollEvent(evnt)) {

			if (evnt.type == sf::Event::Closed) {
				App.close();
			}

			if (evnt.type == sf::Event::Resized) {
				Vector2u newSize(evnt.size.width, evnt.size.height);
				newSize.x = std::max(minSize.x, std::min(newSize.x, maxSize.x));
				newSize.y = std::max(minSize.y, std::min(newSize.y, maxSize.y));
				App.setSize(newSize);
			}
		}
		App.clear();
		App.display();
	}
}