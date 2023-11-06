#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "ventana");

    Texture texture;
    Sprite sprites[4];

    texture.loadFromFile("rcircle.png");

    for (int i = 0; i < 4; i++) {
        sprites[i].setTexture(texture);
        float x = (i % 2 == 0) ? 60.0f : 740.0f;
        float y = (i < 2) ? 60.0f : 540.0f;
        sprites[i].setPosition(x, y);
        sprites[i].setOrigin(sprites[i].getGlobalBounds().width / 2, sprites[i].getGlobalBounds().height / 2);
    }

    while (App.isOpen()) {
        Event evnt;
        sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
        int spritex = -1;

        while (App.pollEvent(evnt)) {
            if (evnt.type == sf::Event::Closed) {
                App.close();
            }
        }


        for (int i = 0; i < 4; i++) {
            if (sprites[i].getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                spritex = i;
                break;
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left) && spritex != -1) {
            sprites[spritex].setPosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
        }

        App.clear();

        for (int i = 0; i < 4; i++) {
            App.draw(sprites[i]);
        }

        App.display();
    }

    return 0;
}