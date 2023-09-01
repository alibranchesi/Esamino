#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>

#include "doctest.h"

template <typename T>
class Rational
{
private:
    T n_{};
    T d_{};

public:
    Rational(T num = 1, T den = 1) : n_{num}, d_{den} //costruttore
    {
        assert(d_ != 0);

        T gcd = std::gcd(n_, d_);
        n_ /= gcd;
        d_ /= gcd;

        if (d_ < 0)
        {
            d_ *= -1;
            n_ *= -1;
        }
    }

    T num() const {return n_;} //funzione per leggere il valore
    T den() const {return d_;}


};