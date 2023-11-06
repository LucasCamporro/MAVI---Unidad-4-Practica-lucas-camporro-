#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture1;
Sprite sprite1;
Texture texture2;
Sprite sprite2;

int main() {

	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"ventana");

	App.setFramerateLimit(60);

	texture1.loadFromFile("cuad_yellow.png");
	sprite1.setTexture(texture1);

	texture2.loadFromFile("rcircle.png");
	sprite2.setTexture(texture2);

	sprite1.setOrigin(sprite1.getGlobalBounds().width / 2, sprite1.getGlobalBounds().height / 2);
	sprite2.setOrigin(sprite2.getGlobalBounds().width / 2, sprite2.getGlobalBounds().height / 2);

	int Posisionx = 400;
	int Posisiony = 300;
	sprite1.setPosition(Posisionx, Posisiony);
	sprite2.setPosition(Posisionx, Posisiony);

	sprite1.setScale(0.5, 0.5);

	float cuadSizex = sprite1.getGlobalBounds().width / sprite2.getGlobalBounds().width;
	float cuadSizey = sprite1.getGlobalBounds().height / sprite2.getGlobalBounds().height;

	sprite2.setScale(cuadSizex, cuadSizey);

	int i = 0;

	bool spacePressed = true;

	int Index = 0;

	while (App.isOpen())
	{
		Event evnt;
		while (App.pollEvent(evnt)) {

			if (evnt.type == sf::Event::Closed) {
				App.close();
			}

		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (spacePressed)
			{
				spacePressed = false;
				if (Index == 0) {
					i = 0;
					Index = 1;
				}
				else
				{
					i = 1;
					Index = 0;
				}
			}
		}

		Vector2f lol = sprite1.getPosition();
		if (Keyboard::isKeyPressed(Keyboard::Space) == false) { spacePressed = true; }

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			if (lol.y > 120) {
				sprite1.move(0, -5);
				sprite2.move(0, -5);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			if (lol.y < 480) {
				sprite1.move(0, 5);
				sprite2.move(0, 5);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			if (lol.x > 120) {
				sprite1.move(-5, 0);
				sprite2.move(-5, 0);
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			if (lol.x < 680) {
				sprite1.move(5, 0);
				sprite2.move(5, 0);
			}
		}

		App.clear();

		if (i == 0)
		{
			App.draw(sprite1);
		}
		else
		{
			App.draw(sprite2);

		}
		App.display();
	}
}