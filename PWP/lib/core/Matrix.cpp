// #include "Matrix.hpp"
// #include <stdexcept>

// using namespace PWP::lib::core;

// Matrix::Matrix() {
//   this->_rows = 0;
//   this->_columns = 0;
//   this->_size = 0;
//   this->_elements = std::vector<float>();
// }

// Matrix::Matrix(unsigned int rows, unsigned int columns) {
//   this->_rows = rows;
//   this->_columns = columns;
//   this->_size = rows * columns;
//   this->_elements.resize(this->_size);
//   for (unsigned int i = 0; i < this->_size; i++) {
//     this->_elements[i] = 0;
//   }
// }

// Matrix::Matrix(unsigned int columns, unsigned int rows,
//                std::vector<float> elements) {
//   this->_rows = rows;
//   this->_columns = columns;
//   this->_size = rows * columns;
//   this->_elements = elements;
// }

// float Matrix::operator()(unsigned int rowIndex,
//                          unsigned int columnsIndex) const {
//   return this->_elements[rowIndex * this->_columns + columnsIndex];
// }

// Matrix Matrix::operator+(Matrix matrix) const {
//   if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
//     throw std::runtime_error(
//         "Invalid matrices dimensions for addition operation");
//   }
//   Matrix result(this->_rows, this->_columns);
//   for (int index = 0; index < result._size; index++) {
//     result._elements[index] = this->_elements[index] + matrix._elements[index];
//   }
//   return result;
// }

// Matrix Matrix::operator-(Matrix matrix) const {
//   if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
//     throw std::runtime_error(
//         "Invalid matrices dimensions for addition operation");
//   }
//   Matrix result(this->_rows, this->_columns);
//   for (int index = 0; index < result._size; index++) {
//     result._elements[index] = this->_elements[index] - matrix._elements[index];
//   }
//   return result;
// }

// Matrix Matrix::operator*(Matrix matrix) const {
//   if (this->_rows != matrix._rows || this->_columns != matrix._columns) {
//     throw std::runtime_error(
//         "Invalid matrices dimensions for addition operation");
//   }
// }