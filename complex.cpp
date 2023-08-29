#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <string>
#include <cmath>
#include "doctest.h"
class Complex
{
private:
    double r;
    double i;

public:
    Complex(double x, double y) : r{x}, i{y} {};
    double real() { return r; }
    double imag() { return i; }
};

bool operator==(Complex c1, Complex c2);
double norm2(Complex c);
Complex conj(Complex c);
Complex operator+(Complex c1, Complex c2);
Complex operatorx(Complex c1, Complex c2);
Complex operator-(Complex c1, Complex c2);
Complex operator/(Complex c1, Complex c2);

bool operator==(Complex c1, Complex c2)
{
    return c1.real() == c2.real() && c1.imag() == c2.imag();
}

double norm2(Complex c)
{
    return c.real() * c.real() + c.imag() * c.imag();
}

Complex conj(Complex c)
{
    return Complex{c.real(), c.imag() * (-1)};
}

Complex operator+(Complex c1, Complex c2)
{
    return Complex{c1.real() + c2.real(), c1.imag() + c2.imag()};
}

Complex operator-(Complex c1, Complex c2)
{
    return Complex{c1.real() - c2.real(), c1.imag() - c2.imag()};
}

Complex operatorx(Complex c1, Complex c2)
{
    return Complex{(c1.real() * c2.real()) + (c1.imag() * c2.imag()),
                   (c1.imag() * c2.real()) + (c1.real() * c2.imag())};
}

Complex operator/(Complex c1, Complex c2)
{
    return Complex { (c1.real() * c2.real() + c1.imag() * c2.imag()) /
                         (c2.real() * c2.real() + c2.imag() * c2.imag()),
                     (c1.imag() * c2.real() - c1.real() * c2.imag()) /
                      (c2.real() * c2.real() + c2.imag() * c2.imag()) };
}





TEST_CASE("Testing Complex") {
  SUBCASE("Testing .real()") {
    Complex r{3, 4};

    CHECK(r.real() == 3);

    Complex a{3.2, 4.5};
    CHECK(a.real() == 3.2);
  }

  SUBCASE("Testing .imag()") {
    Complex r{3, 4};
    CHECK(r.imag() == 4);

    Complex a{3.2, 4.5};
    CHECK(a.imag() == 4.5);
  }

  SUBCASE("Testing + operator") {
    Complex a{2, 2};
    Complex b{3, 3};
    Complex c{3.0, 3.0};

    CHECK(a + b == Complex{5, 5});
    CHECK(a + c == Complex{5.0, 5.0});
  }

  SUBCASE("Testing - operator") {
    Complex a{2, 2};
    Complex b{3, 3};
    Complex c{3.0, 3.0};

    CHECK(a - b == Complex{-1, -1});
    CHECK(a - c == Complex{-1.0, -1.0});
  }
  /*SUBCASE("Testing x operator") {
    Complex a{8, -5};
    Complex b{3, -2};
    Complex c{3.0, -2.0};

    CHECK(a*b == Complex{14, -31});
    CHECK(a*c == Complex{14.0, -31.0});
  }*/ //BOH
  SUBCASE("Testing / operator") {
    Complex a{5, 3};
    Complex b{2, -4};
    auto result = a / b;
    CHECK(result.real() == -0.1);
    CHECK(result.imag() == 1.3);

    Complex c{7, 4};
    Complex d{-3, -1};
    auto result1 = c / d;
    CHECK(result1.real() == -2.5);
    CHECK(result1.imag() == -0.5);
  }
  SUBCASE("Testing norm2") {
    Complex a{3, 2};
    CHECK(norm2(a) == 13);
  }
  SUBCASE("Testing conjugate") {
    Complex a{2, 3};
    Complex b{2.0, 3.0};

    CHECK(conj(a) == Complex{2, -3});
    CHECK(conj(b) == Complex{2.0, -3.0});
  }
}