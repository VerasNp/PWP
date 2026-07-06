#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
#include "linear_systems/ILinearSystem.hpp"
#include <memory>
#include <utility>
namespace PWP::lib::numeric_methods::eigenvalue_problems {
class PowerMethod {
  public:
    auto static calculateRegular(core::Matrix matrix, core::Vector vector, double threshold)
        -> std::pair<double, PWP::lib::core::Vector>;

    auto static calculateInverse(core::Matrix matrix, core::Vector vector, double threshold,
                                 std::shared_ptr<linear_systems::ILinearSystem> solver)
        -> std::pair<double, PWP::lib::core::Vector>;

    auto static calculateShifted(core::Matrix matrix, core::Vector vector, double threshold,
                                 double shift) -> std::pair<double, PWP::lib::core::Vector>;

    auto static buildShiftedMatrix(core::Matrix matrix, double shift) -> core::Matrix;
};
} // namespace PWP::lib::numeric_methods::eigenvalue_problems