#include "Game.h"
#include "MainMenu.h"
Game::Game() {
    font.loadFromFile(FONT_FILEPATH);
    Init();
}

void Game::Init() {
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            grid[x][y] = x + 4 * y + 1;
            sf::Vector2f position(x * CELL_SIZE + 10.f, y * CELL_SIZE + 10.f);
            tile_grid[x][y]._tile.setPosition(position);
        }
    }

    empty.x = SIZE - 1;
    empty.y = SIZE - 1;

    is_solved = true;
}

bool Game::Check() {
    for (unsigned int x = 0; x < SIZE; x++) {
        for (unsigned int y = 0; y < SIZE; y++) {
            if (grid[x][y] != 4 * y + x + 1) {
                return false;
            }
        }
    }
    return true;
}
TileIndex::TileIndex(int x_, int y_) : y(y_), x(x_) {
}

TileIndex::TileIndex() {}
void Game::Move(Direction direction) {

    TileIndex moved(-1, -1);
    if ((direction == Direction::Left) && (empty.x < (SIZE - 1))) {
        moved.x = empty.x + 1;
        moved.y = empty.y;
    }
    if ((direction == Direction::Right) && (empty.x > 0)) {
        moved.x = empty.x - 1;
        moved.y = empty.y;
    }
    if ((direction == Direction::Up) && (empty.y < (SIZE - 1))) {
        moved.y = empty.y + 1;
        moved.x = empty.x;
    }
    if ((direction == Direction::Down) && (empty.y > 0)) {
        moved.y = empty.y - 1;
        moved.x = empty.x;
    }

    if ((moved.x >= 0) && (empty.x >= 0)) {
        int tmp = grid[empty.x][empty.y];
        grid[empty.x][empty.y] = grid[moved.x][moved.y];
        grid[moved.x][moved.y] = tmp;

        empty = moved;
    }
    is_solved = Check();
}

Tile::Tile(int val, float x, float y) {
    _tile.setPosition(sf::Vector2f(x, y));
    tile_texture.loadFromFile(TILE_TEXTURE_FILEPATH);
    _tile.setTexture(tile_texture);
}
Tile::Tile() {
    tile_texture.loadFromFile(TILE_TEXTURE_FILEPATH);
    _tile.setTexture(tile_texture);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    sf::Color color = sf::Color::White;
    sf::Text text("", font, 100);

    for (unsigned int x = 0; x < SIZE; x++) {
        for (unsigned int y = 0; y < SIZE; y++) {
            text.setFillColor(color);
            text.setString(std::to_string(grid[x][y]));

            if (grid[x][y] < 16) {
                sf::Vector2f position(x * CELL_SIZE + 10.f,
                                      y * CELL_SIZE + 10.f);
                target.draw(tile_grid[x][y]._tile, states);

                text.setPosition(position.x + 40.f +
                                     (grid[x][y] < 10 ? 30.f : 0.f),
                                 position.y + 25.f);
                target.draw(text, states);
            }
        }
    }
    if (is_solved) {
        sf::Text wintext = {"(SOLVED)", font, 25};
        wintext.setPosition(700.f, -40.f);
        target.draw(wintext, states);
    }
}