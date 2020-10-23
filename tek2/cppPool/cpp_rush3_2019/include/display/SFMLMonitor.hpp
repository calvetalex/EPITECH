/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** SFMLMonitor
*/

#ifndef SFMLMONITOR_HPP_
    #define SFMLMONITOR_HPP_
    #include <string>
    #include <list>
    #include <map>
    #include "AMonitorDisplay.hpp"
    #include "SFML/Graphics.hpp"
    #include "SFML/Window.hpp"

    //! \class SFMLMonitor [SFMLMonitor.hpp] [SFMLMONITOR_HPP_]
    //! \brief Manage SFML Display
    //  Manage all methods and informations calls for SFML
    class SFMLMonitor : public AMonitorDisplay {
        public:
            explicit SFMLMonitor(const std::list<std::string> &moduleList);
            SFMLMonitor(const SFMLMonitor &initial);
            ~SFMLMonitor();
            const SFMLMonitor &operator=(const SFMLMonitor &rhs);

            void displayModule(void);
            void displayCoreModule(void);
            void displayTimeModule(void);
            void displayUserModule(void);
            void displayOsModule(void);

            void setWidgetNumber(int);
            int getWidgetNumber(void);
            void setWindow(sf::RenderWindow *);
            sf::RenderWindow *getWindows(void);
            void setFont(const sf::Font &);
            const sf::Font &getFont(void);
            void drawGrid(void);
            int getHeightNb(void);

        protected:
        private:
            int _widgetNumber;
            sf::RenderWindow *_window;
            sf::Font _font;

    };

    static const int REFRESH_TIME = 1;
    static const int MODULE_WIDTH = 640; // 1920 / 3
    static const int MODULE_HEIGHT = 360; // 1080 / 3
    static const std::string WINDOWS_NAME("MyGKrellM");
    static const std::string ASSETS_FOLDER("assets/");
    static const std::string BACKGROUND(ASSETS_FOLDER + "background.jpg");
    static const std::string FONT(ASSETS_FOLDER + "arial.ttf");

#endif
