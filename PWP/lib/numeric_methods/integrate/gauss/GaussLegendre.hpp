#pragma once

#include "integrate/GaussRule.hpp"
#include <cmath>

namespace PWP::lib::numeric_methods::integrate::GaussLegendre {

inline const GaussRule GL2 = {
    { -1.0/std::sqrt(3.0), 1.0/std::sqrt(3.0) },
    { 1.0, 1.0 }
};

inline const GaussRule GL3 = {
    { -std::sqrt(0.6), 0.0, std::sqrt(0.6) },
    { 5.0/9.0, 8.0/9.0, 5.0/9.0 }
};

inline const GaussRule GL4 = {
    { -std::sqrt(3.0/7.0 + 2.0/7.0*std::sqrt(6.0/5.0)),
      -std::sqrt(3.0/7.0 - 2.0/7.0*std::sqrt(6.0/5.0)),
       std::sqrt(3.0/7.0 - 2.0/7.0*std::sqrt(6.0/5.0)),
       std::sqrt(3.0/7.0 + 2.0/7.0*std::sqrt(6.0/5.0)) },
    { (18.0 - std::sqrt(30.0))/36.0,
      (18.0 + std::sqrt(30.0))/36.0,
      (18.0 + std::sqrt(30.0))/36.0,
      (18.0 - std::sqrt(30.0))/36.0 }
};

} // namespace PWP::lib::numeric_methods::integrate::GaussLegendre
