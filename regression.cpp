#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <iostream>
#include <cmath>
#include <stdexcept>

struct Result
{
    double A{};
    double B{};
};


class Regression
{
    private:
    int N{};
    double sum_x{};
    double sum_y{};
    double sum_x2{};
    double sum_xy{};

    public: 
    void add(double x, double y) {
        ++N;
        sum_x+=x;
        sum_y+=y;
        sum_x2+=x*x;
        sum_xy+=x*y;
    }
    Result fit() const {
        if (N < 2) {
      throw std::runtime_error{"Not enough points to run a fit"};
    }
    if (((N*sum_x2)-std::pow(sum_x, 2)) == 0.) {
      throw std::runtime_error{"Trying to fit a vertical line"};
    }
        double const a = ((sum_y*sum_x2)-(sum_x*sum_xy))/((N*sum_x2)-std::pow(sum_x, 2));
        double const b = ((N*sum_xy)-(sum_x*sum_y))/((N*sum_x2)-std::pow(sum_x, 2));
        return {a,b};} 

};



TEST_CASE("Testing Regression") {
  Regression reg;

  SUBCASE("Fitting with no points throws") { CHECK_THROWS(reg.fit()); }

  SUBCASE("Fitting on one point throws") {
    reg.add(0., 0.);
    CHECK_THROWS(reg.fit());
  }

  SUBCASE("Fitting on two, vertically aligned, points throws") {
    reg.add(1., 0.);
    reg.add(1., 2.);
    CHECK_THROWS(reg.fit());
  }

  SUBCASE("Fitting on two points") {
    reg.add(0., 0.);
    reg.add(1., 1.);
    auto result = reg.fit();
    CHECK(result.A == doctest::Approx(0));
    CHECK(result.B == doctest::Approx(1));
  }

  SUBCASE("Fitting on two points, negative slope") {
    reg.add(0., 1.);
    reg.add(1., 0.);
    auto result = reg.fit();
    CHECK(result.A == doctest::Approx(1));
    CHECK(result.B == doctest::Approx(-1));
  }

  SUBCASE("Fitting on five points") {
    reg.add(2.1, 3.2);
    reg.add(6.9, 7.3);
    reg.add(2.2, 3.0);
    reg.add(0.1, 1.3);
    reg.add(4.7, 5.6);
    auto result = reg.fit();
    CHECK(result.A == doctest::Approx(1.2).epsilon(0.01));
    CHECK(result.B == doctest::Approx(0.9).epsilon(0.01));
  }
}
