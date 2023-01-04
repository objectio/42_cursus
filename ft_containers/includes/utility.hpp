#ifndef UTILITY_HPP
#define UTILITY_HPP

# include "containers.hpp"

namespace ft {
    template <class T1, class T2>
    struct pair {
        /*  MEMBER TYPES */
        typedef T1 first_type;
        typedef T2 second_type;

        public:
        /* MEMBER VARIABLES */
        T1 first;
        T2 second;

        /* MEMBER FUNCTIONS */
        pair() : first(), second() { }

        template<class U, class V>
        pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) { }

        pair (const first_type& a, const second_type& b) : first(a), second(b) { }
    };
}

#endif