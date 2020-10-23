/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** SFMLMonitor
*/

#include <iostream>
#include "display/SFMLMonitor.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

SFMLMonitor::SFMLMonitor(const std::list<std::string> &moduleList) :
                            AMonitorDisplay(moduleList)
{
    _widgetNumber = 0;
}

SFMLMonitor::SFMLMonitor(const SFMLMonitor &initial) :
                            AMonitorDisplay(initial)
{
    _widgetNumber = initial._widgetNumber;
}

SFMLMonitor::~SFMLMonitor()
{
}

const SFMLMonitor &SFMLMonitor::operator=(const SFMLMonitor &rhs)
{
    this->_modules = rhs._modules;
    return *this;
}

void SFMLMonitor::displayModule(void)
{
    setWidgetNumber(0);
    if (_modules.find("UserModule") != _modules.end()) {
        displayUserModule();
        setWidgetNumber(_widgetNumber + 1);
    }
    if (_modules.find("TimeModule") != _modules.end()) {
        displayTimeModule();
        setWidgetNumber(_widgetNumber + 1);
    }
    if (_modules.find("CoreModule") != _modules.end()) {
        displayCoreModule();
        setWidgetNumber(_widgetNumber + 1);
    }
    if (_modules.find("OsModule") != _modules.end()) {
        displayOsModule();
        setWidgetNumber(_widgetNumber + 1);
    }
}

void SFMLMonitor::displayCoreModule(void)
{
    CoreModule *tmp =  static_cast<CoreModule *>((_modules.find("CoreModule"))->second);
    sf::Text str;
    int heightNb = getHeightNb();

    str.setFont(_font);
    str.setCharacterSize(28);
    str.setString("Number of processes:\t\t" + tmp->getProcess());
    str.setFillColor(sf::Color(255, 0, 0, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 30);
    _window->draw(str);

    str.setString("Total Ram:\t\t\t" + tmp->getTotalRam() + "MB");
    str.setFillColor(sf::Color(0, 0, 153, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 110);
    _window->draw(str);

    str.setString("Total Used Ram:\t\t" + tmp->getUseRam() + "MB");
    str.setFillColor(sf::Color(179, 179, 0, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 160);
    _window->draw(str);

    str.setString("Total Swap:\t\t\t\t" + tmp->getTotalSwap() + "MB");
    str.setFillColor(sf::Color(0, 0, 153, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 240);
    _window->draw(str);

    str.setString("Total Used Swap:\t\t\t" + tmp->getUseSwap() + "MB");
    str.setFillColor(sf::Color(179, 179, 0, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 280);
    _window->draw(str);
}

void SFMLMonitor::displayOsModule(void)
{
    OsModule *tmp =  static_cast<OsModule *>((_modules.find("OsModule"))->second);
    sf::Text str;
    sf::Texture texture;
    int heightNb = getHeightNb();

    str.setFont(_font);
    str.setCharacterSize(22);
    texture.loadFromFile("assets/linux.png");
    sf::Sprite sprite(texture);
    sprite.setPosition(MODULE_WIDTH * _widgetNumber + 470, MODULE_HEIGHT * heightNb + 30);
    sprite.setScale(sf::Vector2f{0.1, 0.1});
    _window->draw(sprite);

    str.setString("OS:\t\t" + tmp->getOs());
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 50);
    _window->draw(str);

    str.setString("Kernel version:\t\t" + tmp->getKernel());
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 120);
    _window->draw(str);

    str.setString("CPU:\t\t" + tmp->getCpu());
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 190);
    _window->draw(str);

     str.setString("GPU:\t\t" + tmp->getGpu());
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 260);
    _window->draw(str);
}

void SFMLMonitor::displayTimeModule(void)
{
    TimeModule *tmp =  static_cast<TimeModule *>((_modules.find("TimeModule"))->second);
    sf::Text str;
    int heightNb = getHeightNb();

    str.setFont(_font);
    str.setCharacterSize(30);

    str.setString("Date:\t\t" + tmp->getDate());
    str.setFillColor(sf::Color(204, 51, 0153, 200));
        str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 90);
    _window->draw(str);

    str.setString("Uptime:\t\t" + tmp->getUpTime());
    str.setPosition(MODULE_WIDTH * _widgetNumber + 80, MODULE_HEIGHT * heightNb + 220);
    _window->draw(str);

}

void SFMLMonitor::displayUserModule(void)
{
    UserModule *tmp =  static_cast<UserModule *>((_modules.find("UserModule"))->second);
    sf::Text str;
    int heightNb = getHeightNb();
    sf::Texture texture;

    str.setFont(_font);
    str.setCharacterSize(38);
    texture.loadFromFile("assets/user.png");
    sf::Sprite sprite(texture);
    sprite.setPosition(MODULE_WIDTH * _widgetNumber + 460, MODULE_HEIGHT * heightNb + 100);
    sprite.setScale(sf::Vector2f{0.07, 0.07});
    _window->draw(sprite);
    str.setString("Username:\t\t" + tmp->getUserName());
    str.setFillColor(sf::Color(77, 153, 0, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 70);
    _window->draw(str);

    str.setString("Hostname:\t\t" + tmp->getUserName());
    str.setFillColor(sf::Color(128, 0, 0, 200));
    str.setPosition(MODULE_WIDTH * _widgetNumber + 40, MODULE_HEIGHT * heightNb + 220);
    _window->draw(str);

}

int SFMLMonitor::getWidgetNumber(void)
{
    return _widgetNumber;
}

void SFMLMonitor::setWidgetNumber(int number)
{
    _widgetNumber = number;
}

void SFMLMonitor::setWindow(sf::RenderWindow *window)
{
    _window = window;
}


sf::RenderWindow *SFMLMonitor::getWindows(void)
{
    return _window;
}

void SFMLMonitor::setFont(const sf::Font &font)
{
    _font = font;
}

const sf::Font &SFMLMonitor::getFont(void)
{
    return _font;
}

void SFMLMonitor::drawGrid(void)
{
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(MODULE_WIDTH, 0)),
        sf::Vertex(sf::Vector2f(MODULE_WIDTH, 1080))
    };
    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(MODULE_WIDTH * 2, 0)),
        sf::Vertex(sf::Vector2f(MODULE_WIDTH * 2, 1080))
    };
    sf::Vertex line4[] = {
        sf::Vertex(sf::Vector2f(0, MODULE_HEIGHT)),
        sf::Vertex(sf::Vector2f(1920, MODULE_HEIGHT))
    };
    sf::Vertex line5[] = {
        sf::Vertex(sf::Vector2f(0, MODULE_HEIGHT * 2)),
        sf::Vertex(sf::Vector2f(1920 * 3, MODULE_HEIGHT * 2))
    };

    _window->draw(line, 2, sf::Lines);
    _window->draw(line2, 2, sf::Lines);
    _window->draw(line4, 2, sf::Lines);
    _window->draw(line5, 2, sf::Lines);
}

int SFMLMonitor::getHeightNb(void)
{
    int heightNb = 0;
    if (getWidgetNumber() >= 3) {
        heightNb = 1;
        setWidgetNumber(getWidgetNumber() % 3);
    }
    if (getWidgetNumber() >= 6) {
        setWidgetNumber(getWidgetNumber() % 3);
        heightNb = 2;
    }
    return heightNb;
}
