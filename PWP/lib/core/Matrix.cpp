#include "Matrix.hpp"
#include <sys/types.h>
PWP::lib::core::Matrix::Matrix(uint rows, uint columns) {
    this->elements_ = nullptr;
    this->buffer_ = nullptr;
    this->rows_ = rows;
    this->columns_ = columns;
    uint pixelCount = this->rows_ * this->columns_;
    this->elements_ = new core::element_row[this->rows_];
    this->buffer_ = new core::element[pixelCount];
    for (uint i = 0; i < this->rows_; i++) {
        this->elements_[i] = &buffer_[i * this->columns_];
    }
    for (uint i = 0; i < pixelCount; i++) {
        this->buffer_[i] = 0;
    }
}

PWP::lib::core::Matrix::Matrix(uint rows, uint columns, const double &value) {
    this->elements_ = nullptr;
    this->buffer_ = nullptr;
    this->rows_ = rows;
    this->columns_ = columns;
    uint pixelCount = this->rows_ * this->columns_;
    this->elements_ = new core::element_row[this->rows_];
    this->buffer_ = new core::element[pixelCount];
    for (uint i = 0; i < this->rows_; i++) {
        this->elements_[i] = &buffer_[i * this->columns_];
    }
    for (uint i = 0; i < pixelCount; i++) {
        this->buffer_[i] = value;
    }
}

PWP::lib::core::Matrix::Matrix(uint rows, uint columns, const double *values) {
    this->elements_ = nullptr;
    this->buffer_ = nullptr;
    this->rows_ = rows;
    this->columns_ = columns;
    uint pixelCount = this->rows_ * this->columns_;
    this->elements_ = new core::element_row[this->rows_];
    this->buffer_ = new core::element[pixelCount];
    for (uint i = 0; i < this->rows_; i++) {
        this->elements_[i] = &buffer_[i * this->columns_];
    }
    for (uint i = 0; i < pixelCount; i++) {
        this->buffer_[i] = values[i];
    }
}

PWP::lib::core::Matrix::Matrix(const Matrix &other) {
    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    uint pixelCount = this->rows_ * this->columns_;
    this->elements_ = new core::element_row[this->rows_];
    this->buffer_ = new core::element[pixelCount];
    for (uint i = 0; i < this->rows_; i++) {
        this->elements_[i] = &this->buffer_[i * this->columns_];
    }
    for (uint i = 0; i < pixelCount; i++) {
        this->buffer_[i] = other.buffer_[i];
    }
}

PWP::lib::core::Matrix::~Matrix() {
    if (this->elements_ != nullptr) {
        delete[] this->buffer_;
        delete[] this->elements_;

        this->elements_ = 0;
        this->rows_ = 0;
        this->columns_ = 0;
    }
}

auto PWP::lib::core::Matrix::transpose() -> Matrix {
    Matrix transposed(this->columns_, this->rows_);
    for (uint i = 0; i < this->rows_; i++) {
        for (uint j = 0; j < this->columns_; j++) {
            transposed[j][i] = this->elements_[i][j];
        }
    }
    return transposed;
}

auto PWP::lib::core::Matrix::isSymmetric() -> bool {
    for (uint i = 0; i < this->rows_; i++) {
        for (uint j = 0; j < this->columns_; j++) {
            if (i != j && this->elements_[i][j] != this->elements_[j][i]) {
                return false;
            }
        }
    }
    return true;
}

auto PWP::lib::core::Matrix::operator*(PWP::lib::core::Matrix matrix) -> PWP::lib::core::Matrix {
    PWP::lib::core::Matrix result(this->rows_, matrix.columns_);
    for (uint i = 0; i < this->rows_; i++) {
        for (uint j = 0; j < matrix.columns_; j++) {
            core::element sum = 0.0;
            for (uint k = 0; k < this->columns_; k++) {
                sum += this->elements_[i][k] * matrix.elements_[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

auto PWP::lib::core::Matrix::operator=(const Matrix &other) -> Matrix & {
    if (this == &other) {
        return *this;
    }
    if (this->elements_ != nullptr) {
        delete[] this->buffer_;
        delete[] this->elements_;
    }
    this->rows_ = other.rows_;
    this->columns_ = other.columns_;
    uint pixelCount = this->rows_ * this->columns_;
    this->elements_ = new core::element_row[this->rows_];
    this->buffer_ = new core::element[pixelCount];
    for (uint i = 0; i < this->rows_; i++) {
        this->elements_[i] = &this->buffer_[i * this->columns_];
    }
    for (uint i = 0; i < pixelCount; i++) {
        this->buffer_[i] = other.buffer_[i];
    }
    return *this;
}