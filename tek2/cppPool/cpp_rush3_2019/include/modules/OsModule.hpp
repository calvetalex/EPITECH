/*
** EPITECH PROJECT, 2020
** OsModule
** File description:
** OsModule
*/

#ifndef OSMODULE_HPP_
    #define OSMODULE_HPP_

    #include <string>
    #include "AMonitorModule.hpp"

    //! \class OsModule [OsModule.hpp] [OSMODULE]
    //! \brief OsModule Class
    class OsModule: public AMonitorModule {
        public:
            OsModule();
            OsModule(const OsModule&);
            ~OsModule();
            const OsModule &operator=(const OsModule&);
            const std::string &getKernel(void);
            const std::string &getOs(void);
            const std::string &getGpu(void);
            const std::string &getCpu(void);
            void extractInfos(void);

        private:
            void setOs(const std::string &os);
            void setKernel(const std::string &kernel);
            void setGpu(const std::string &gpu);
            void setCpu(const std::string &cpu);

            std::string _os;
            std::string _kernelVersion;
            std::string _cpu;
            std::string _gpu;
    };

static const std::string CPUCOMMAND("cat /proc/cpuinfo | grep -m 1 \"model name\" | cut -d ' ' -f 3- > " + TMP_FILE_PATH);
static const std::string GPUCOMMAND("lspci -mm | awk -F '\\\"|\\\" \\\"|\\\\(' '/\"Display|\"3D|\"VGA/ {a[$0] = $1 \" \" $3 \" \" $4} END {for(i in a) {if(!seen[a[i]]++) print a[i]}}' | cut -d ' ' -f3- > " + TMP_FILE_PATH);

#endif /* !OSMODULE_HPP_ */
