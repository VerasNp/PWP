#pragma once

#include "integrate/GaussRule.hpp"
#include <cmath>
#include <numbers>

namespace PWP::lib::numeric_methods::integrate::GaussHermite {

inline const GaussRule GH2 = {
    { -1.0/std::sqrt(2.0),  1.0/std::sqrt(2.0) },
    {  std::sqrt(std::numbers::pi)/2.0, std::sqrt(std::numbers::pi)/2.0 }
};

inline const GaussRule GH3 = {
    { -std::sqrt(1.5), 0.0, std::sqrt(1.5) },
    {  std::sqrt(std::numbers::pi)/6.0, 2.0*std::sqrt(std::numbers::pi)/3.0, std::sqrt(std::numbers::pi)/6.0 }
};

inline const GaussRule GH4 = {
    { -std::sqrt((3.0+std::sqrt(6.0))/2.0),
      -std::sqrt((3.0-std::sqrt(6.0))/2.0),
       std::sqrt((3.0-std::sqrt(6.0))/2.0),
       std::sqrt((3.0+std::sqrt(6.0))/2.0) },
    {  std::sqrt(std::numbers::pi)*(3.0-std::sqrt(6.0))/12.0,
       std::sqrt(std::numbers::pi)*(3.0+std::sqrt(6.0))/12.0,
       std::sqrt(std::numbers::pi)*(3.0+std::sqrt(6.0))/12.0,
       std::sqrt(std::numbers::pi)*(3.0-std::sqrt(6.0))/12.0 }
};

} // namespace PWP::lib::numeric_methods::integrate::GaussHermite
