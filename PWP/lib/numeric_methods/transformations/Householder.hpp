#pragma once

#include "Matrix.hpp"

namespace PWP::lib::numeric_methods::transformations {
class Householder {
  public:
    [[nodiscard]] static auto apply(const core::Matrix &matrix) -> core::Matrix;
};
} // namespace PWP::lib::numeric_methods::transformations