#pragma once

#include "utils.hpp"
#include <sys/types.h>

namespace PWP::lib::core {
class Matrix {
  public:
    /**
     * @brief Construct a new Matrix object
     *
     * @param rows Number of rows
     * @param columns Number of columns
     */
    Matrix(uint rows, uint columns);

    /**
     * @brief Initialize to constant value
     *
     * @param rows Number of rows
     * @param columns Number of columns
     * @param value Constant value
     */
    Matrix(uint rows, uint columns, const double &value);

    /**
     * @brief Construct a new Matrix object with given C-style array of values
     *
     * @param rows Number of rows
     * @param columns Number of columns
     * @param values Array of values
     */
    Matrix(uint rows, uint columns, const double *values);

    /**
     * @brief Construct a new Matrix object with copy
     *
     * @param other Matrix to be copied
     */
    Matrix(const Matrix &other);

    /**
     * @brief Destroy the Matrix object
     *
     */
    ~Matrix();

    /**
     * @brief Transposes a matrix
     *
     * @return Matrix A new transposed matrix
     */
    auto transpose() -> Matrix;

    /**
     * @brief Check if is symmetric
     *
     * @return true Matrix is symmetric
     * @return false Matrix isn't symmetric
     */
    auto isSymmetric() -> bool;

    /**
     * @brief Accesses a row
     *
     * @param row Row index (0-based)
     * @return element_row Pointer to the row, allowing element_row[col] access
     */
    auto operator[](uint row) const -> core::element_row { return this->elements_[row]; }

    /**
     * @brief Accesses, and modify if necessary, a row
     *
     * @param row Row index (0-based)
     * @return element_row Pointer to the row, allowing element_row[col] access
     */
    auto operator[](uint row) -> core::element_row { return this->elements_[row]; }

    /**
     * @brief Multiply a matrix by another
     *
     * @param matrix Multiplier matrix
     * @return Matrix The product
     */
    auto operator*(Matrix matrix) -> Matrix;

    /**
     * @brief Assign a matrix to another
     *
     * @param other Matrix to be passed as value
     * @return Matrix& The new assigned matrix
     */
    auto operator=(const Matrix &other) -> Matrix &;

    [[nodiscard]] auto getRows() const -> uint { return this->rows_; }

    [[nodiscard]] auto getColumns() const -> uint { return this->rows_; }

  private:
    uint rows_;                   ///< Number of rows
    uint columns_;                ///< Number of columns
    core::element_row *elements_; ///< Array of row pointers
    core::element_row buffer_;    ///< Contiguous memory buffer
};
} // namespace PWP::lib::core