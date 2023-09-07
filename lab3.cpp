#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <cmath>

struct Statistics
{
    double mean{};
    double sigma{};
    double mean_err{};
    double median{};
};

class Sample
{
private:
    std::vector<double> entries_{};

public:
    int size() const { return entries_.size(); }
    const auto& entries() const {return entries_;}
    void add(double x)
    {
        entries_.push_back(x);
    }
    bool remove(double x)
    {
        for (auto it = entries_.begin(), end = entries_.end(); it != end; ++it)
        {
            if (*it == x)
            {
                entries_.erase(it);
                return true;
            }
        }
        return false;
    }
    Statistics statistics() const
    {
        double sum_x{};
        double sum_x2{};
        for (auto const &e : entries_)
        {
            sum_x += e;
            sum_x2 += e * e;
        }
        if (size() < 2)
        {
            throw std::runtime_error{"Not enough points to run an statistics"};
        }

        auto entries{entries_};
        std::sort(entries.begin(), entries.end());

        const double mean = sum_x / size();
        const double sigma = std::sqrt((sum_x2 - size() * mean * mean) / (size() - 1));
        const double mean_err = sigma / std::sqrt(size());
        const double median = size() % 2 == 0
                                  ? (entries[size() / 2 - 1] + entries[size() / 2]) * 0.5
                                  : entries[size() / 2];

        return {mean, sigma, mean_err, median};
    }

     Sample& operator+=(const Sample& r) {
    entries_.reserve(size() + r.size());
    entries_.insert(entries_.end(), r.entries().begin(), r.entries().end());
    return *this;
  }
};

Sample operator+(const Sample& l, const Sample& r){
    Sample sum{l};
    return sum += r;
}



TEST_CASE("Testing the class handling a floating point data sample")
{
    Sample sample;

    REQUIRE(sample.size() == 0);

    SUBCASE("Calling size() with four points")
    {
        sample.add(1.0);
        sample.add(1.5);
        sample.add(2.0);
        sample.add(2.5);
        CHECK(sample.size() == 4);
    }

    SUBCASE("Calling statistics() with no points throws")
    {
        CHECK_THROWS(sample.statistics());
    }

    SUBCASE("Calling statistics() with one point throws")
    {
        sample.add(4.0);
        CHECK_THROWS(sample.statistics());
    }

    SUBCASE("Calling statistics() with two points")
    {
        sample.add(1.);
        sample.add(2.);
        auto result = sample.statistics();
        CHECK(result.mean == doctest::Approx(1.5));
        CHECK(result.sigma == doctest::Approx(0.70710678));
        CHECK(result.mean_err == doctest::Approx(0.5));
    }

    SUBCASE("Calling statistics() with two identical points")
    {
        sample.add(10.);
        sample.add(10.);
        auto result = sample.statistics();
        CHECK(result.mean == doctest::Approx(10.0));
        CHECK(result.sigma == doctest::Approx(0.0));
        CHECK(result.mean_err == doctest::Approx(0.0));
    }

    SUBCASE("Calling statistics() with five points")
    {
        sample.add(1.5);
        sample.add(2.0);
        sample.add(2.5);
        sample.add(3.0);
        sample.add(3.5);
        auto result = sample.statistics();
        CHECK(result.mean == doctest::Approx(2.5));
        CHECK(result.sigma == doctest::Approx(0.79056942));
        CHECK(result.mean_err == doctest::Approx(0.35355339));
    }
}