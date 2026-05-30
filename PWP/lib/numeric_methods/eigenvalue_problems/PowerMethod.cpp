#include "eigenvalue_problems/PowerMethod.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "matrices_factorization/LUDecomposition.hpp"
#include <cstdlib>

auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
    core::Matrix matrix, core::Vector vector, double threshold)
    -> std::pair<double, PWP::lib::core::Vector> {
    double eigenValueNew = 0;
    double eigenValueOld = 0;
    double erro = threshold + 1;
    core::Vector vectorNew(vector);
    while (erro > threshold) {
        double eigenValueOld = eigenValueNew;
        core::Vector vectorOld(vectorNew);
        core::Vector vectorOldNormalized = vectorOld.normalize();
        vectorNew = matrix * vectorOldNormalized;
        eigenValueNew = vectorOldNormalized.dot(vectorNew);
        erro = std::abs(eigenValueNew - eigenValueOld);
    }
    core::Vector eigenVector = vectorNew.normalize();
    return std::make_pair(eigenValueNew, eigenVector);
}

// auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateInverse(
//     core::Matrix matrix, core::Vector vector, double threshold)
//     -> std::pair<double, PWP::lib::core::Vector> {
//     core::Matrix luDecomposition = matrices_factorization::LUDecomposition::execute(matrix);
//     double eigenValueNew = 0;
//     core::Vector vectorNew(vector);
//     double erro = threshold + 1;
//     while (erro > threshold) {
//         double eigenValueOld = eigenValueNew;
//         core::Vector vectorOld(vectorNew);
//         core::Vector vectorOldNormalized = vectorOld.normalize();
//     }
// }