/*
** EPITECH PROJECT, 2020
** QtMonitor
** File description:
** rendering Qt5 program
*/

#ifndef QtMonitor_HPP_
    #define QtMonitor_HPP_

    #include "AMonitorDisplay.hpp"

    class QtMonitor: public AMonitorDisplay {
        public:
            QtMonitor();
            QtMonitor(const QtMonitor&);
            ~QtMonitor();
            QtMonitor &operator=(const QtMonitor &);

        protected:
        private:
    };

#endif /* !QtMonitor_HPP_ */