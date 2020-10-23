/*
** EPITECH PROJECT, 2020
** WarpSystem
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
        public:
            QuantumReactor();
            ~QuantumReactor();
            bool isStable(void);
            void setStability(bool);

        private:
            bool _stability;
    };

    class Core {
        public:
            Core(QuantumReactor *);
            ~Core();
            QuantumReactor *checkReactor(void);
        private:
            QuantumReactor *_coreReactor;
    };
};

#endif /* !WARPSYSTEM_HPP_ */
