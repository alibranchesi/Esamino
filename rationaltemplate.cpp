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
    Rational(T numerator = 0, T denominator = 1)
        : n_{numerator}, d_{denominator}
    {
        {
            if (d_ == 0)
            {
                throw std::runtime_error{"denominator is zero"};
            }
        }
        T mcd = std::gcd(n_, d_);
        n_ /= mcd;
        d_ /= mcd;

        if (d_ < 0)
        {
            d_ *= -1;
            n_ *= -1;
        }
    }

    T numerator() const { return n_; }
    T denominator() const { return d_; }
    void print() const
    {
        std::cout << '\n'
                  << n_ << "\n- = " << calculate(Rational{n_, d_}) << '\n'
                  << d_ << "\n\n";
    }
};

template <typename T, typename R>
bool operator==(Rational<T> const &a, Rational<R> const &b)
{
    return a.numerator() == b.numerator() && a.denominator() == b.denominator();
}

template <typename T, typename R>
auto operator+(Rational<T> const &a, Rational<R> const &b)
{
    T den = std::lcm(a.denominator(), b.denominator());
    T num = den / a.denominator() * a.numerator() + den / b.denominator() * b.numerator();
    return Rational<T>{num, den};
}

template <typename T> // Perché questo overload????
auto operator+(Rational<T> const &a, int b)
{
    T den = std::lcm(a.denominator(), 1);
    T num = den / a.denominator() * a.numerator() + den / b;

    return Rational<T>{num, den};
}

template <typename T>
auto operator++(Rational<T> const &a)
{
    return Rational<T>{a.numerator() + a.denominator(), a.denominator()};
}

template <typename T, typename R>
auto operator-(Rational<T> const &a, Rational<R> const &b)
{
    T den = std::lcm(a.denominator(), b.denominator());
    T num = den / a.denominator() * a.numerator() - den / b.denominator() * b.numerator();
    return Rational<T>{num, den};
}

template <typename T> // Perché questo overload????
auto operator-(Rational<T> const &a, int b)
{
    T den = std::lcm(a.denominator(), 1);
    T num = den / a.denominator() * a.numerator() - den / b;
    assert(den > 0);

    return Rational<T>{num, den};
}

template <typename T>
auto operator--(Rational<T> const &a)
{
    return Rational<T>{a.numerator() - a.denominator(), a.denominator()};
}

template <typename T, typename R>
auto operator*(Rational<T> const &a, Rational<R> const &b)
{
    return Rational<T>{a.numerator() * b.numerator(), a.denominator() * b.denominator()};
}

template <typename T>
auto operator^(Rational<T> const &a, int power)
{
    assert(power > 0);
    int num = pow(a.numerator(), power);
    int den = pow(a.denominator(), power);
    return Rational<T>{num, den};
}

template <typename T, typename R>
auto operator/(Rational<T> const &a, Rational<R> const &b)
{
    assert(b.numerator() != 0 && a.denominator() != 0);
    return Rational<T>{a.numerator() * b.denominator(), a.denominator() * b.numerator()};
}

template <typename T>
double calculate(Rational<T> const &a)
{
    return double(a.numerator()) / a.denominator();
}


TEST_CASE("Testing Rational Class") {
  SUBCASE("Denominator is negative") {
    Rational<int> r{3, -4};
    CHECK(r.denominator() == 4);
    CHECK(r.numerator() == -3);

    Rational<int> f{-3, -4};
    CHECK(f.denominator() == 4);
    CHECK(f.numerator() == 3);
  }

  SUBCASE("Testing gcd") {
    Rational<int> r{6, 8};
    CHECK(r.numerator() == 3);
    CHECK(r.denominator() == 4);

    Rational<long int> a{6, 8};
    CHECK(a.numerator() == 3);
    CHECK(a.denominator() == 4);
  }

  SUBCASE("== Operator") {
    Rational<int> a{6, 6};
    Rational<int> b{6, 12};

    CHECK(!(a == b));

    Rational<long int> c{1, 2};
    Rational<long int> d{1, 2};
    CHECK(d == c);

    CHECK(d == b);
    CHECK(Rational<int>{1, 2} == Rational<int>{2, 4});
  }

  SUBCASE("+ Operator") {
    Rational<int> a{3, 6};
    Rational<int> b{6, 12};

    CHECK(a + b == Rational<int>{1, 1});

    Rational<long int> c{1, 5};
    Rational<long int> d{3, -2};
    CHECK(c + d == Rational<int>{-13, 10});

    CHECK(a + c == Rational<int>{7, 10});
    CHECK(a + 1 == Rational<int>{3, 2});
  }
  SUBCASE("- Operator") {
    Rational<int> a{3, 6};
    Rational<int> b{6, 12};

    CHECK(a - b == Rational<int>{0, 1});

    Rational<int> c{1, 5};
    Rational<long int> d{3, 2};
    CHECK(c - d == Rational<int>{-13, 10});
    CHECK(c - 1 == Rational<int>{-4, 5});
  }

  SUBCASE("++ Operator") {
    Rational<int> a{2, 4};

    CHECK(++a == Rational<int>{3, 2});
  }

  SUBCASE("-- Operator") {
    Rational<int> a{2, 4};

    CHECK(--a == Rational<int>{-1, 2});
  }

  SUBCASE("* Operator") {
    Rational<int> a{2, 4};
    Rational<long int> b{2, -4};

    CHECK(a * b == Rational<int>{-1, 4});
  }
  SUBCASE("/ Operator") {
    Rational<int> a{2, 4};
    Rational<long int> b{2, -4};

    CHECK(a / b == Rational<int>{-1, 1});
  }
  SUBCASE("^ Operator (Raise to power)") {
    Rational<int> a{2, 4};
    Rational<long int> b{2, 3};

    CHECK((a ^ 2) == Rational<int>{1, 4});
    CHECK((b ^ 2) == Rational<int>{4, 9});
    CHECK((b ^ 2.5) == Rational<int>{4, 9});
  }
  SUBCASE("Calculate fraction") {
    Rational<int> a{2, 4};
    Rational<int> b{1, 3};
    CHECK(calculate(a) == 0.5);
    CHECK(doctest::Approx(calculate(b)) == 0.3333333333);
  }

  SUBCASE("Print rational number") {
    Rational<int> a{2, 4};
    a.print();
  }
}