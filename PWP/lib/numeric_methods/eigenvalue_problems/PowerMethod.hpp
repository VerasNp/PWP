#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include <utility>
namespace PWP::lib::numeric_methods::eigenvalue_problems {
class PowerMethod {
  public:
    auto static calculateRegular(core::Matrix matrix, core::Vector vector, double threshold)
        -> std::pair<double, PWP::lib::core::Vector>;
};
} // namespace PWP::lib::numeric_methods::eigenvalue_problems