/*
** EPITECH PROJECT, 2020
** NcurseMonitor
** File description:
** rendering ncurse program
*/

#ifndef NCURSEMONITOR_HPP_
    #define NCURSEMONITOR_HPP_

    #include <list>
    #include <map>
    #include "display/AMonitorDisplay.hpp"
    #include "modules/IMonitorModule.hpp"


    //! \class NcurseMonitor [NcurseMonitor.hpp] [NCURSEMONITOR_HPP]
    //! \brief Manage Ncurse Display
    //  Manage all methods and informations calls for Ncurse
    class NcurseMonitor: public AMonitorDisplay {
        public:
            explicit NcurseMonitor(std::list<std::string>&);
            NcurseMonitor(const NcurseMonitor&);
            ~NcurseMonitor();
            NcurseMonitor& operator=(const NcurseMonitor&);

            void displayModule(void) override;
            void displayUserModule(void);
            void displayTimeModule(void);
            void displayOsModule(void);
            void displayCoreModule(void);

            int16_t getMaxX(void) const;
            int16_t getMaxY(void) const;
            void setMaxX(int16_t);
            void setMaxY(int16_t);
        private:
            int16_t _maxX;
            int16_t _maxY;
    };

#endif /* !NCURSEMONITOR_HPP_ */
