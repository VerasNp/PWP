#pragma once

#include "integrate/Stencil.hpp"
#include <cmath>

namespace PWP::lib::numeric_methods::integrate::GaussLegendre {

inline const Stencil GL2 = {
    {1.0, 1.0},
    {(1.0 - 1.0/std::sqrt(3.0))/2.0,
     (1.0 + 1.0/std::sqrt(3.0))/2.0},
    2.0
};

inline const Stencil GL3 = {
    {5.0/9.0, 8.0/9.0, 5.0/9.0},
    {(1.0 - std::sqrt(0.6))/2.0,
     0.5,
     (1.0 + std::sqrt(0.6))/2.0},
    2.0
};

inline const Stencil GL4 = {
    {(18.0 - std::sqrt(30.0))/36.0,
     (18.0 + std::sqrt(30.0))/36.0,
     (18.0 + std::sqrt(30.0))/36.0,
     (18.0 - std::sqrt(30.0))/36.0},
    {(1.0 - std::sqrt(3.0/7.0 + 2.0/7.0*std::sqrt(6.0/5.0)))/2.0,
     (1.0 - std::sqrt(3.0/7.0 - 2.0/7.0*std::sqrt(6.0/5.0)))/2.0,
     (1.0 + std::sqrt(3.0/7.0 - 2.0/7.0*std::sqrt(6.0/5.0)))/2.0,
     (1.0 + std::sqrt(3.0/7.0 + 2.0/7.0*std::sqrt(6.0/5.0)))/2.0},
    2.0
};

} // namespace PWP::lib::numeric_methods::integrate::GaussLegendre
