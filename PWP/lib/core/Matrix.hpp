// #include <vector>
// namespace PWP::lib::core {
// class Matrix {
// private:
//   unsigned int _columns;
//   unsigned int _rows;
//   unsigned int _size;
//   std::vector<float> _elements;

// public:
//   Matrix();
//   Matrix(unsigned int columns, unsigned int rows);
//   Matrix(unsigned int columns, unsigned int rows, std::vector<float> elements);

// public:
//   float operator()(unsigned int rowIndex, unsigned int columnsIndex) const;
//   Matrix operator+(Matrix matrix) const;
//   Matrix operator-(Matrix matrix) const;
//   Matrix operator*(Matrix matrix) const;

// public:
//   Matrix transpose();
//   bool isSquare();
//   bool isLowerTriangular();
//   bool isUpperTriangular();
// };
// } // namespace PWP::lib::core