#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace sf;

class Crosshair {
public:
    Crosshair() {
        texturaCrosshair.loadFromFile("Crosshair.png");
        spriteCrosshair.setTexture(texturaCrosshair);
        spriteCrosshair.setScale(0.5, 0.5);
    }

    void setSpritePosition(float x, float y) {
        spriteCrosshair.setPosition(x, y);
    }

    Sprite getSprite() {
        return spriteCrosshair;
    }

private:
    Texture texturaCrosshair;
    Sprite spriteCrosshair;
};

class ET {
public:
    ET() {
        texturaET.loadFromFile("et.png");
        spriteET.setTexture(texturaET);
        spriteET.setOrigin(spriteET.getGlobalBounds().width / 2, spriteET.getGlobalBounds().height / 2);
        spriteET.setScale(0.1, 0.1);
        spriteET.setPosition(400, 300);
    }

    void setSpritePosition(float x, float y) {
        spriteET.setPosition(x, y);
    }

    FloatRect getGlobalBounds() {
        return spriteET.getGlobalBounds();
    }

    Sprite getSprite() {
        return spriteET;
    }

private:
    Texture texturaET;
    Sprite spriteET;
};

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600, 32), "ventana");

    std::srand(time(NULL));

    App.setMouseCursorVisible(false);

    Crosshair cross;
    ET et;

    int i = 0;

    while (App.isOpen())
    {
        sf::Event evnt;
        while (App.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                App.close();
            }
            if (evnt.type == sf::Event::MouseMoved)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
                cross.setSpritePosition(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (i >= 5) {
                App.close();
            }
            else {
                FloatRect etBounds = et.getGlobalBounds();
                sf::Vector2i mousePosition = sf::Mouse::getPosition(App);
                if (etBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                    int x = 100 + std::rand() % 600;
                    int y = 100 + std::rand() % 500;
                    et.setSpritePosition(static_cast<float>(x), static_cast<float>(y));
                    i += 1;
                }
            }
        }

        App.clear();
        App.draw(et.getSprite());
        App.draw(cross.getSprite());
        App.display();
    }

    return 0;
}