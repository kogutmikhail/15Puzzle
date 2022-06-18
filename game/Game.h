#pragma once
#include <SFML/Graphics.hpp>
#include "GameConf.h"
/**
 * Описание класса Direction
 *
 * @brief - Класс для хранения направления
 *
 *
 */ 
enum class Direction {
	Left = 0, Right = 1, Up = 2, Down = 3 
	};
/**
 * Описание класса TileIndex
 *
 * @brief - Класс для хранения координат тайла
 *
 *
 */ 

struct TileIndex{
	int x;
	int y;
/**
 * Описание конструктора TileIndex(int x_,int y_)
 *
 * @brief - Конструктор
 *
 * @param x_ - координата X
 * @param y_ - координата Y

 * Создается пара координат
 *
 */ 
	TileIndex(int x_,int y_);
/**
 * Описание конструктора TileIndex()
 *
 * @brief - Конструктор
 *
 *
 */ 
	TileIndex();
};

/**
 * Описание класса Tile
 *
 * @brief - Класс для хранения данных о тайле
 *
 *
 */ 

struct Tile
{
sf::Texture tile_texture;
sf::Sprite _tile;
/**
 * Описание Tile(int val, float x, float y)
 *
 * @brief - Конструктор
 *
 * @param val - значение
 * @param x - координата X
 * @param y - координата Y
 */ 

Tile(int val, float x, float y);
/**
 * Описание Tile()
 *
 * @brief - Конструктор
 *
 */ 

Tile();
};

/**
 * Описание класса Game
 *
 * @brief - Класс для обЪекта игры
 *
 */ 
class Game : public sf::Drawable, public sf::Transformable
{
private:
	Tile tile_grid[SIZE][SIZE];
	sf::Font font;
public:
	int grid[SIZE][SIZE];
	bool is_solved;
	TileIndex empty;
/**
 * Описание конструктора Game()
 *
 * @brief - Конструктор
 *
 */ 
	Game();
/**
 * Описание функции Check()
 *
 * @brief - Проверяет решенность игры
 *
 */ 
	bool Check();
/**
 * Описание функции Init()
 *
 * @brief - заполняет массив элементов
 *
 */ 
	void Init();
/**
 * Описание функции Move(Direction direction);
 *
 * @brief - передвигает тайлы при вводе
 *
 * @param direction - направление
 */ 
	void Move(Direction direction);
/**
 * Описание функции draw(sf::RenderTarget& target, sf::RenderStates states)
 * 
 * @brief - отрисовывает объекты
 *
 * @param target - объекты отрисовки
 *
 * @param states - параметры отрисовки
 */ 
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
/**
 * Описание функции play(sf::RenderWindow& window);
 * 
 * @brief - начинает игру и обрабатывает ввод
 *
 * @param window - окно отрисовки
 */ 
	void play(sf::RenderWindow& window);
};
