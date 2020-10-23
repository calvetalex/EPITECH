/*
** EPITECH PROJECT, 2020
** UserModule
** File description:
** UserModule
*/

#ifndef USERMODULE_HPP_
    #define USERMODULE_HPP_

    #include <string>
    #include <unistd.h>
    #include <pwd.h>
    #include <iostream>
    #include <streambuf>
    #include <fstream>

    #include "IMonitorModule.hpp"

    //! \class UserModule [UserModule.hpp] [USERMODULE]
    //! \brief UserModule Class
    class UserModule: public IMonitorModule {
        public:
            UserModule();
            UserModule(const UserModule &);
            ~UserModule();
            UserModule &operator=(const UserModule&);

            void extractInfos(void);
            void setHostName(const std::string &hostname);
            void setUserName(const std::string &username);
            const std::string &getUserName(void);
            const std::string &getHostName(void);
        private:
            std::string _username;
            std::string _hostname;
    };

#endif /* !UserModule_HPP_ */
