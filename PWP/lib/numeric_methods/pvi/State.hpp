#pragma once

#include <cmath>
#include <functional>
#include <vector>
namespace PWP::lib::numeric_methods::pvi {

using State = std::vector<double>;
using ODEFunction = std::function<State(const State &, double)>;

inline auto operator+(const State &a, const State &b) -> State {
    State result(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        result[i] = a[i] + b[i];
    return result;
}

inline auto operator-(const State &a, const State &b) -> State {
    State result(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        result[i] = a[i] - b[i];
    return result;
}

inline auto operator*(double scalar, const State &a) -> State {
    State result(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        result[i] = scalar * a[i];
    return result;
}

inline auto norm(const State &a) -> double {
    double sum = 0.0;
    for (double v : a)
        sum += v * v;
    return std::sqrt(sum);
}

inline auto relativeDifference(const State &a, const State &b) -> double {
    double diffNorm = norm(a - b);
    double refNorm = norm(a);
    return (refNorm < 1e-14) ? diffNorm : diffNorm / refNorm;
}

} // namespace PWP::lib::numeric_methods::pvi