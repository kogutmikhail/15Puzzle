#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
/**
 * Описание класса MainMenu
 *
 * @brief - Класс для создания главного меню
 *
 *
 */

class MainMenu {
  private:
    sf::RenderWindow &_window;
    sf::Sprite _background;

  public:
    sf::Texture backgroundtexture;
    /**
     * Описание конструктора MainMenu
     *
     * @brief - Конструктор
     *
     * @param window - окно отрисовки

     * Создается главное меню
     *
     */
    MainMenu(sf::RenderWindow &window);
    /**
     * Описание функции init()
     *
     * @brief - Инициализация

     * Инициализуется главное меню
     *
     */
    void init();
    /**
     * Описание функции handleInput()
     *
     * @brief - Обрабатывает ввод
     *
     */
    int handleInput();
    /**
     * Описание функции draw()
     *
     * @brief - рисует меню
     *
     * Отрисовывается главное меню
     *
     */
    void draw();
};
