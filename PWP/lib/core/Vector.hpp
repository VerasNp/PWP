#pragma once

#include "utils.hpp"
#include <sys/types.h>

namespace PWP::lib::core {

class Vector {
  public:
    enum class Orientation { Row, Column };

    Vector(uint size, Orientation orientation = Orientation::Column);
    Vector(uint size, const double &value, Orientation orientation = Orientation::Column);
    Vector(uint size, const double *values, Orientation orientation = Orientation::Column);
    Vector(const Vector &other);
    ~Vector();

    auto transpose() -> Vector;
    auto normalize() -> Vector;
    auto magnitude() -> double;
    auto dot(Vector vector) -> double;

    auto operator=(const Vector &other) -> Vector &;
    auto operator[](uint index) const -> double { return this->elements_[index]; }
    auto operator[](uint index) -> double & { return this->elements_[index]; }

    [[nodiscard]] auto getSize() const -> uint { return this->size_; }

    [[nodiscard]] auto getOrientation() const -> Orientation { return this->orientation_; }

  private:
    Orientation orientation_;
    uint size_;
    element_row elements_;
};

} // namespace PWP::lib::core