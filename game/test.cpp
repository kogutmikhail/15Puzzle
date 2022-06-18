#include "Game.h"
#include <doctest.h>

TEST_CASE("Solve check") {
    Game game;
    game.Init();
    REQUIRE(game.is_solved == true);
    game.Move(Direction::Left);
    REQUIRE(game.is_solved == true);
    game.Move(Direction::Right);
    REQUIRE(game.is_solved == false);
}

TEST_CASE("Empty check") {
    Game game;
    game.Init();
    for (int i = 0; i < SIZE; i++) {
        game.Move(Direction::Right);
        game.Move(Direction::Down);
    }
    REQUIRE(game.grid[0][0] == game.grid[game.empty.x][game.empty.y]);
}