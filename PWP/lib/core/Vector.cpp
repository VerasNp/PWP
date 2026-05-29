#include "Vector.hpp"
#include "utils.hpp"
#include <cmath>
#include <sys/types.h>

PWP::lib::core::Vector::Vector(uint size, Orientation orientation) {
    this->size_ = size;
    this->orientation_ = orientation;
    this->elements_ = new double[size];
    for (uint i = 0; i < size; i++) {
        this->elements_[i] = 0;
    }
}

PWP::lib::core::Vector::Vector(uint size, const double &value, Orientation orientation) {
    this->size_ = size;
    this->orientation_ = orientation;
    this->elements_ = new double[size];
    for (uint i = 0; i < size; i++) {
        this->elements_[i] = value;
    }
}

PWP::lib::core::Vector::Vector(uint size, const double *values, Orientation orientation) {
    this->size_ = size;
    this->orientation_ = orientation;
    this->elements_ = new double[size];
    for (uint i = 0; i < size; i++) {
        this->elements_[i] = values[i];
    }
}

PWP::lib::core::Vector::Vector(const Vector &other) {
    this->size_ = other.size_;
    this->orientation_ = other.orientation_;
    this->elements_ = new double[this->size_];
    for (uint i = 0; i < this->size_; i++) {
        this->elements_[i] = other.elements_[i];
    }
}

auto PWP::lib::core::Vector::operator=(const Vector &other) -> Vector & {
    if (this == &other) {
        return *this;
    }

    delete[] this->elements_;
    this->size_ = other.size_;
    this->orientation_ = other.orientation_;
    this->elements_ = new double[this->size_];

    for (uint i = 0; i < this->size_; i++) {
        this->elements_[i] = other.elements_[i];
    }

    return *this;
}

PWP::lib::core::Vector::~Vector() {
    if (this->elements_ != nullptr) {
        delete[] this->elements_;
        this->elements_ = nullptr;
    }
}

auto PWP::lib::core::Vector::transpose() -> Vector {
    Vector transposed(this->size_, this->orientation_ == Orientation::Row ? Orientation::Column
                                                                          : Orientation::Row);
    for (uint i = 0; i < this->size_; i++) {
        transposed[i] = this->elements_[i];
    }
    return transposed;
}

auto PWP::lib::core::Vector::magnitude() -> double { return std::sqrt(this->dot(*this)); }

auto PWP::lib::core::Vector::normalize() -> Vector {
    double magnitude = this->magnitude();
    auto *normalizedItems = new double[this->size_];
    for (uint i = 0; i < this->size_; i++) {
        normalizedItems[i] = this->elements_[i] / magnitude;
    }
    Vector normalizedVector(this->size_, normalizedItems);
    delete[] normalizedItems;
    return normalizedVector;
}
auto PWP::lib::core::Vector::dot(PWP::lib::core::Vector vector) -> double {
    double sum = 0;
    for (uint i = 0; i < this->size_; i++) {
        sum += this->elements_[i] * vector.elements_[i];
    }
    return sum;
}