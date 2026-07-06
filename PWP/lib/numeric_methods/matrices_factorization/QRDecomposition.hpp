#pragma once

#include "Matrix.hpp"

namespace PWP::lib::numeric_methods::matrices_factorization {
class QRDecomposition {
  public:
    explicit QRDecomposition(const core::Matrix &matrix);
    auto execute() -> void;
    [[nodiscard]] auto getQ() const -> core::Matrix { return this->Q_; };
    [[nodiscard]] auto getR() const -> core::Matrix { return this->R_; };

  private:
    core::Matrix matrix_; 
    core::Matrix Q_;
    core::Matrix R_;
};
} // namespace PWP::lib::numeric_methods::matrices_factorization