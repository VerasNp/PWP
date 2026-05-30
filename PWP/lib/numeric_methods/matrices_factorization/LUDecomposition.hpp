#pragma once

#include "Matrix.hpp"
namespace PWP::lib::numeric_methods::matrices_factorization {
class LUDecomposition {
  public:
    auto static execute(core::Matrix &matrix) -> core::Matrix;
};
} // namespace PWP::lib::numeric_methods::matrices_factorization