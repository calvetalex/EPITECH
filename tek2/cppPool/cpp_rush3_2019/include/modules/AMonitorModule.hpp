/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** AMonitorModule
*/

#ifndef AMONITORMODULE_HPP_
    #define AMONITORMODULE_HPP_
    #include <string>
    #include "IMonitorModule.hpp"

    class AMonitorModule : public IMonitorModule {
        public:
            AMonitorModule();
            ~AMonitorModule();

        protected:
            std::string getInfosFromShell(const std::string &command);

        private:
    };


#endif
