/*
** EPITECH PROJECT, 2020
** CoreModule
** File description:
** Monitor CoreModule
*/

#ifndef CoreModule_HPP_
    #define CoreModule_HPP_

    #include "IMonitorModule.hpp"
    #include <sys/sysinfo.h>

    //! \class CoreModule [CoreModule.hpp] [COREMODULE]
    //! \brief CoreModule Class
    class CoreModule: public IMonitorModule {
        public:
            CoreModule();
            CoreModule(const CoreModule&);
            ~CoreModule();
            CoreModule &operator=(const CoreModule &);

            void extractInfos();

            void setProcess(const std::string);
            std::string getProcess(void) const;

            void setTotalRam(const std::string);
            std::string getTotalRam(void) const;

            void setFreeRam(const std::string);
            std::string getFreeRam(void) const;

            void setUseRam(const std::string);
            std::string getUseRam(void) const;

            void setTotalSwap(const std::string);
            std::string getTotalSwap(void) const;

            void setFreeSwap(const std::string);
            std::string getFreeSwap(void) const;

            void setUseSwap(const std::string);
            std::string getUseSwap(void) const;
        private:
            std::string _process;
            std::string _totalram;
            std::string _totalswap;
            std::string _freeram;
            std::string _freeswap;
            std::string _useram;
            std::string _useswap;

    };

#endif /* !CoreModule_HPP_ */
