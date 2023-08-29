#include <iostream>
#include <string>
#include <cmath>
#include <numeric>

class Rational
{
private:
    int n_;
    int d_;

public:
    Rational(int num = 0, int den = 0) : n_{num}, d_{den}
    {
        if (d_ == 0)
        {
            std::cout << "Denominator must be different from 0 \n";
        };

        int const g = std::gcd(n_, d_);
        n_ /= g;
        d_ /= g;

        if (d_ < 0)
        {
            n_ = -n_;
            d_ = -d_;
        }
    };
};
