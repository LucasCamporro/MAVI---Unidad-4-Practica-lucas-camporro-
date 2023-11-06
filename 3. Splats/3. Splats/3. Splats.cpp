#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture1;
Sprite sprite1;
Texture texture2;
Sprite sprite2;

int main() {
    texture1.loadFromFile("rcircle.png");
    sprite1.setTexture(texture1);

    texture2.loadFromFile("rcircleb.png");
    sprite2.setTexture(texture2);

    sprite1.setOrigin(sprite1.getGlobalBounds().width / 2, sprite1.getGlobalBounds().height / 2);
    sprite2.setOrigin(sprite2.getGlobalBounds().width / 2, sprite2.getGlobalBounds().height / 2);

    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "ventana");

    while (App.isOpen()) {

        Event evnt;

        Vector2i mousePosition = sf::Mouse::getPosition(App);

        while (App.pollEvent(evnt)) {
            switch (evnt.type) {
            case sf::Event::Closed:
                App.close();
                break;
            }
        }

        switch (evnt.type) {
        case sf::Event::MouseButtonPressed:
            if (evnt.mouseButton.button == sf::Mouse::Left) {
                sprite1.setPosition(static_cast<sf::Vector2f>(mousePosition));
                App.draw(sprite1);
            }
            else if (evnt.mouseButton.button == sf::Mouse::Right) {
                sprite2.setPosition(static_cast<sf::Vector2f>(mousePosition));
                App.draw(sprite2);
            }
            break;
        }

        App.display();
    }
}