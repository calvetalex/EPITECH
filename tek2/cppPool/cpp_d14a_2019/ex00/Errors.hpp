/*
** EPITECH PROJECT, 2020
** Errors
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>

    class NasaError: public std::exception {
        public:
            NasaError(const std::string&, const std::string& = "Unknow");
            virtual ~NasaError() throw();

            virtual const std::string &getComponent(void) const;
            const char *what(void) const throw () override;

        protected:
            std::string _cmp;
        private:
            std::string _msg;
    };

    class LifeCriticalError: public NasaError {
        public:
            LifeCriticalError(const std::string&, const std::string& = "Unknow");
            ~LifeCriticalError() throw ();
        protected:
        private:
    };

    class MissionCriticalError: public NasaError {
        public:
            MissionCriticalError(const std::string&, const std::string& = "Unknow");
            ~MissionCriticalError() throw ();
        protected:
        private:
    };

    class CommunicationError: public NasaError {
        public:
            CommunicationError(const std::string&, const std::string& = "Unknow");
            ~CommunicationError() throw ();
            const std::string &getComponent(void) const override;
    };

    class UserError: public NasaError {
        public:
            UserError(const std::string&, const std::string& = "Unknow");
            ~UserError() throw ();
        protected:
        private:
    };

#endif /* !ERRORS_HPP_ */
