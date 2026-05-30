#pragma once

#include "Matrix.hpp"
namespace PWP::lib::numeric_methods::matrices_factorization {
class LUDecomposition {
  public:
    const double TINY = 1.0e-40;
    auto execute(core::Matrix &matrix) const -> core::Matrix;
};
} // namespace PWP::lib::numeric_methods::matrices_factorization