/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
    #define IMONITORMODULE_HPP_
    #include <map>
    #include <string>

    class IMonitorModule {
        public:
            virtual ~IMonitorModule() = default;
            virtual void extractInfos(void) = 0;
    };

    static const std::string TMP_FILE = "gtm.tmp";
    static const std::string TMP_FILE_PATH = "/tmp/" + TMP_FILE;

#endif /* !IMONITORMODULE_HPP_ */
