/*
** EPITECH PROJECT, 2020
** AmonitorDisplay
** File description:
** Abstract monitor display class
*/

#ifndef AMONITORDISPLAY_HPP_
    #define AMONITORDISPLAY_HPP_

    #include <map>
    #include <string>
    #include <cstdint>
    #include <list>
    #include "display/IMonitorDisplay.hpp"
    #include "modules/IMonitorModule.hpp"
    #include "modules/CoreModule.hpp"
    #include "modules/OsModule.hpp"
    #include "modules/UserModule.hpp"
    #include "modules/TimeModule.hpp"

    //! \class AMonitorDisplay [AMonitorDisplay.hpp] [AMONITORDISPLAY_HPP]
    //! \brief Abstact Class for Display Monitoring
    //  Abstact class that implements all needed method for display
    class AMonitorDisplay: public IMonitorDisplay {
        public:
            AMonitorDisplay(const std::list<std::string> &moduleList);
            AMonitorDisplay(const AMonitorDisplay &);
            ~AMonitorDisplay();
            const AMonitorDisplay &operator=(const AMonitorDisplay &);

            std::map<std::string, uint16_t> getScreenInfo(void) const;
            void setScreenInfo(uint16_t, uint16_t);

            void updateModules(void);
            std::map<std::string, IMonitorModule*> getModules(void) const;
            void resetScreen(void);
        protected:
            std::map<std::string, IMonitorModule *> _modules;
            std::map<std::string, uint16_t> _screenInfo;
    };

#endif /* !AMONITORDISPLAY_HPP_ */
