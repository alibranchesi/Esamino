#include <iostream>
#include <string>
#include <cmath>

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
