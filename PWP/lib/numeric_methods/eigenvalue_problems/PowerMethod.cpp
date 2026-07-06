#include "eigenvalue_problems/PowerMethod.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include "linear_systems/ILinearSystem.hpp"
#include <cstdlib>
#include <memory>

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

auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateInverse(
    core::Matrix matrix, core::Vector vector, double threshold,
    std::shared_ptr<linear_systems::ILinearSystem> solver)
    -> std::pair<double, PWP::lib::core::Vector> {
    double eigenValueNew = 0;
    double eigenValueOld = 0;
    double erro = threshold + 1;
    core::Vector vectorNew(vector);
    while (erro > threshold) {
        eigenValueOld = eigenValueNew;
        core::Vector vectorOld(vectorNew);
        core::Vector vectorOldNormalized = vectorOld.normalize();
        core::Matrix systemMatrix(matrix);
        core::Vector systemVector(vectorOldNormalized);
        vectorNew = solver->solve(systemMatrix, systemVector);
        const double eigenValueInverse = vectorOldNormalized.dot(vectorNew);
        eigenValueNew = 1.0 / eigenValueInverse;
        erro = std::abs(eigenValueNew - eigenValueOld);
    }
    core::Vector eigenVector = vectorNew.normalize();
    return std::make_pair(eigenValueNew, eigenVector);
}

auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateShifted(
    core::Matrix matrix, core::Vector vector, double threshold, double shift)
    -> std::pair<double, PWP::lib::core::Vector> {
    core::Matrix shiftedMatrix = buildShiftedMatrix(matrix, shift);
    double eigenValueNew = 0;
    double eigenValueOld = 0;
    double erro = threshold + 1;
    core::Vector vectorNew(vector);
    while (erro > threshold) {
        eigenValueOld = eigenValueNew;
        core::Vector vectorOld(vectorNew);
        core::Vector vectorOldNormalized = vectorOld.normalize();
        vectorNew = shiftedMatrix * vectorOldNormalized;
        eigenValueNew = vectorOldNormalized.dot(vectorNew);
        erro = std::abs(eigenValueNew - eigenValueOld);
    }
    core::Vector eigenVector = vectorNew.normalize();
    double actualEigenValue = eigenValueNew + shift;
    return std::make_pair(actualEigenValue, eigenVector);
}

auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::buildShiftedMatrix(
    core::Matrix matrix, double shift) -> core::Matrix {
    core::Matrix shifted(matrix);
    for (std::size_t i = 0; i < shifted.getRows(); ++i) {
        shifted[i][i] -= shift;
    }
    return shifted;
}