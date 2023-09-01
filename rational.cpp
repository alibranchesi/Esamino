#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cassert>
#include <numeric>
#include <stdexcept>
// operators and test missin
class Rational
{
  int n_;
  int d_;

  // i due metodi privati seguenti "normalizzano" la frazione, in modo tale che
  // * numeratore e denominatore siano ridotti ai minimi termini
  // * il segno e' mantenuto dal numeratore
  // e' meglio avere due funzioni separate perche' non servono sempre entrambe
  // (vedi operator/=)

  void reduce()
  {
    auto const g = std::gcd(n_, d_);
    n_ /= g;
    d_ /= g;
  }
  void fix_sign()
  {
    if (d_ < 0) {
      n_ = -n_;
      d_ = -d_;
    }
  }

  // funzione che esprime l'invariante di classe
  bool invariant()
  {
    return std::gcd(n_, d_) == 1 && d_ > 0;
  }

 public:
  Rational(int num = 0, int den = 1) : n_{num}, d_{den}
  { if (d_ == 0) {
      throw std::runtime_error{"denominator is zero"};
    }
    reduce();
    fix_sign();
    assert(invariant());
  }

  int num() const
  {
    return n_;
  }
  int den() const
  {
    return d_;
  }

  Rational& operator*=(int n)
  {
    assert(invariant());
    auto g = std::gcd(n, d_);
    n_ *= n / g;
    d_ /= g;
    assert(invariant());
    return *this;
  }

  Rational& operator/=(int n)
  { assert(n != 0);
    assert(invariant());
    auto g = std::gcd(n, n_);
    n_ /= g;
    d_ *= n / g;
    fix_sign();
    assert(invariant());
    return *this;
  }
};


bool operator==(Rational r1, Rational r2);
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operatorx(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);

bool operator==(Rational r1, Rational r2)
{
    return {r1.num() == r2.num() && r1.den() == r2.den()};
}

Rational operator+(Rational r1, Rational r2)
{
    int den = std::lcm(r1.den(), r2.den());
    int num = den / r1.den() * r1.num() +
              den / r2.den() * r2.num();
    return Rational{num, den};
}

Rational operator-(Rational r1, Rational r2)
{
    int den = std::lcm(r1.den(), r2.den());
    int num = den / r1.den() * r1.num() -
              den / r2.den() * r2.num();
    return Rational{num, den};
}

Rational operatorx(Rational r1, Rational r2)
{
    return {r1.num() * r2.num(), r1.den() * r2.den()};
}

Rational operator/(Rational r1, Rational r2)
{
    return {r1.num() * r2.den(), r2.num() * r1.den()};
}