#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <cmath>
#include "doctest.h"



double fact(double N){
    int i=1;
    int fact=1;
    while(i<=N){
        fact *=i;
        i++;
    }
return fact;
}

double cos(double x, int N){
    if (N < 0) {
    return -1.0;
  }
    double cos{};
    for(int n{};n<=N; ++n){
        const int nt2{n * 2};
        cos+=std::pow(-1,n)*std::pow(x, nt2)/fact(nt2);
        n++;
    }
    return cos;
}

TEST_CASE("Testing the factorial function") {
  CHECK(fact(-10) == -1);
  CHECK(fact(1) == 1);
  CHECK(fact(3) == 6);
  CHECK(fact(10) == 3628800);
}

TEST_CASE("Testing the taylor expansion function") {
  CHECK(cos(0.5, 0) == doctest::Approx(1.0));
  CHECK(cos(0.5, 1) == doctest::Approx(0.875));
  CHECK(cos(0.5, 2) == doctest::Approx(0.877).epsilon(0.001));
  CHECK(cos(0.5, 3) == doctest::Approx(0.877).epsilon(0.001));
  CHECK(cos(0.5, -9) == doctest::Approx(-1.0));
}