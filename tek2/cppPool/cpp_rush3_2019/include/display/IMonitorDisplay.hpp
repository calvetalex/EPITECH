/*
** EPITECH PROJECT, 2020
** IMonotirDisplay
** File description:
** Interface Monitor Display
*/

#ifndef IMONITORDISPLAY_HPP_
    #define IMONITORDISPLAY_HPP_
    #include "modules/OsModule.hpp"
    #include "modules/TimeModule.hpp"
    #include "modules/UserModule.hpp"
    #include "modules/CoreModule.hpp"

    //! \class IMonitorDisplay [IMonitorDisplay.hpp] [IMONITORDISPLAY_HPP]
    //! \brief Interface Class for Display Monitoring
    //  Interface class that implements all needed method for display
    class IMonitorDisplay {
        public:
            virtual ~IMonitorDisplay(void) = default;
            virtual void displayCoreModule(void) = 0;
            virtual void displayUserModule(void) = 0;
            virtual void displayTimeModule(void) = 0;
            virtual void displayOsModule(void) = 0;
            virtual void displayModule(void) = 0;
    };

#endif /* !IMONITORDISPLAY_HPP_ */
