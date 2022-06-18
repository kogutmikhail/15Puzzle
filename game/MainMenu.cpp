#include "MainMenu.h"
#include "GameConf.h"

MainMenu::MainMenu(sf::RenderWindow &window) : _window(window){};

void MainMenu::init() {
    backgroundtexture.loadFromFile(GAME_BACKGROUND_TEXTURE_FILEPATH);
    _background.setTexture(backgroundtexture);
}

int MainMenu::handleInput() {
    sf::Event event{};
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed)
            return 1;
    }
    return 0;
}
void MainMenu::draw() {
    _window.clear();
    _window.draw(_background);

    _window.display();
}