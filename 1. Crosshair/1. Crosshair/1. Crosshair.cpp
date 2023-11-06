#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
Sprite sprite;

int main() {

	texture.loadFromFile("crosshair.png");

	sprite.setTexture(texture);

	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
	sprite.setPosition(400,300);

	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"ventana");


	while (App.isOpen())
	{
		App.clear();
		App.draw(sprite);
		App.display();
	}
	return 0;
}