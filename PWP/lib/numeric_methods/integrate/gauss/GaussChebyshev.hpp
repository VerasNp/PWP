#pragma once

#include "integrate/GaussRule.hpp"
#include <cmath>
#include <numbers>

namespace PWP::lib::numeric_methods::integrate::GaussChebyshev {

namespace T1 {

inline const GaussRule GC2 = {
    { std::cos(std::numbers::pi/4.0), std::cos(3.0*std::numbers::pi/4.0) },
    { std::numbers::pi/2.0, std::numbers::pi/2.0 }
};

inline const GaussRule GC3 = {
    { std::cos(std::numbers::pi/6.0), 0.0, std::cos(5.0*std::numbers::pi/6.0) },
    { std::numbers::pi/3.0, std::numbers::pi/3.0, std::numbers::pi/3.0 }
};

inline const GaussRule GC4 = {
    { std::cos(  std::numbers::pi/8.0), std::cos(3.0*std::numbers::pi/8.0),
      std::cos(5.0*std::numbers::pi/8.0), std::cos(7.0*std::numbers::pi/8.0) },
    { std::numbers::pi/4.0, std::numbers::pi/4.0, std::numbers::pi/4.0, std::numbers::pi/4.0 }
};

} // namespace T1


namespace T2 {

namespace detail {
    inline double s2(double t) { return std::sin(t) * std::sin(t); }
}

inline const GaussRule GC2 = {
    { std::cos(std::numbers::pi/3.0), std::cos(2.0*std::numbers::pi/3.0) },
    { (std::numbers::pi/3.0)*detail::s2(  std::numbers::pi/3.0),
      (std::numbers::pi/3.0)*detail::s2(2.0*std::numbers::pi/3.0) }
};

inline const GaussRule GC3 = {
    { std::cos(std::numbers::pi/4.0), 0.0, std::cos(3.0*std::numbers::pi/4.0) },
    { (std::numbers::pi/4.0)*detail::s2(  std::numbers::pi/4.0),
      (std::numbers::pi/4.0)*detail::s2(2.0*std::numbers::pi/4.0),
      (std::numbers::pi/4.0)*detail::s2(3.0*std::numbers::pi/4.0) }
};

inline const GaussRule GC4 = {
    { std::cos(  std::numbers::pi/5.0), std::cos(2.0*std::numbers::pi/5.0),
      std::cos(3.0*std::numbers::pi/5.0), std::cos(4.0*std::numbers::pi/5.0) },
    { (std::numbers::pi/5.0)*detail::s2(  std::numbers::pi/5.0),
      (std::numbers::pi/5.0)*detail::s2(2.0*std::numbers::pi/5.0),
      (std::numbers::pi/5.0)*detail::s2(3.0*std::numbers::pi/5.0),
      (std::numbers::pi/5.0)*detail::s2(4.0*std::numbers::pi/5.0) }
};

} // namespace T2

} // namespace PWP::lib::numeric_methods::integrate::GaussChebyshev
