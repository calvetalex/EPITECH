/*
** EPITECH PROJECT, 2020
** TimeModule
** File description:
** get Time and Date
*/

#ifndef TIMEMODULE_HPP_
    #define TIMEMODULE_HPP_

    #include "IMonitorModule.hpp"
    #include <sys/sysinfo.h>
    #include <stdlib.h>
    #include <iostream>

    //! \class TimeModule [TimeModule.hpp] [TIMEMODULE]
    //! \brief TimeModule Class
    class TimeModule: public IMonitorModule{
        public:
            TimeModule();
            TimeModule(const TimeModule &);
            ~TimeModule();
            const TimeModule &operator=(const TimeModule&);

            void extractInfos(void);
            std::string getDate(void) const;
            void setDate(const std::string);
            std::string getUpTime(void) const;
            void setUpTime(const std::string);
        private:
            std::string _date;
            std::string _uptime;
    };

#endif /* !TIMEMODULE_HPP_ */
