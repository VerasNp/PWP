#pragma once

#include "Matrix.hpp"
#include "Vector.hpp"
namespace PWP::lib::numeric_methods::linear_systems {
class ILinearSystem {
  public:
    virtual auto solve(core::Matrix &coefficientMatrix, core::Vector &constantVector)
        -> core::Vector = 0;
};
} // namespace PWP::lib::numeric_methods::linear_systems