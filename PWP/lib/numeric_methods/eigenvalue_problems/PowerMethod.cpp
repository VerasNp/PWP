#include "eigenvalue_problems/PowerMethod.hpp"
#include "Vector.hpp"

auto PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
    core::Matrix matrix, core::Vector vector, double threshold)
    -> std::pair<double, PWP::lib::core::Vector> {
    double eigenValueNew = 0;
    double eigenValueOld = 0;
    double erro = 0;
    core::Vector vectorNew(vector);
    while (erro > threshold) {
        double eigenValueOld = eigenValueNew;
        core::Vector vectorOld(vectorNew);
    }
}