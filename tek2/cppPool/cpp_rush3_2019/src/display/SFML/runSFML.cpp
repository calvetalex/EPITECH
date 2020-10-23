/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** SFML_main
*/

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "display/SFMLMonitor.hpp"

int runSFML(const std::list<std::string> &options)
{
    SFMLMonitor monitor(options);

    sf::RenderWindow window(sf::VideoMode(1920, 1080), WINDOWS_NAME);
    window.setFramerateLimit(REFRESH_TIME);
    sf::Texture texture;
        if (!texture.loadFromFile(BACKGROUND))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sf::Font font;
    if (!font.loadFromFile(FONT))
        return EXIT_FAILURE;

    monitor.setWindow(&window);
    monitor.setFont(font);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                window.close();
        }
        monitor.updateModules();
        window.clear(sf::Color::White);
        window.draw(sprite);
        monitor.drawGrid();

        monitor.displayModule();
        window.display();
    }
    return EXIT_SUCCESS;
}
