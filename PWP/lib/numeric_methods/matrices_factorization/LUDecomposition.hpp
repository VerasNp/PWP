#pragma once

#include "Matrix.hpp"

namespace PWP::lib::numeric_methods::matrices_factorization {
class LUDecomposition {
  public:
    LUDecomposition(PWP::lib::core::Matrix &matrix);
    auto execute() -> core::Matrix;
    [[nodiscard]] auto getPermutation() -> core::Vector { return this->permutation_; }
    [[nodiscard]] auto getLUDecomposition() -> core::Matrix { return this->luDecomposition_; }

  private:
    core::Matrix luDecomposition_;
    core::Vector permutation_;
};
} // namespace PWP::lib::numeric_methods::matrices_factorization