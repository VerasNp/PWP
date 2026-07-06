#include "eigenvalue_problems/PowerMethod.hpp"
#include "Matrix.hpp"
#include "linear_systems/direct_methods/GaussElimination.hpp"
#include <cmath>
#include <doctest.h>

using PWP::lib::core::Matrix;
using PWP::lib::core::Vector;
using PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod;

namespace {

auto buildTestMatrix() -> PWP::lib::core::Matrix {
    PWP::lib::core::Matrix m(3, 3);
    m[0][0] = 4;
    m[0][1] = 1;
    m[0][2] = 0;
    m[1][0] = 1;
    m[1][1] = 4;
    m[1][2] = 1;
    m[2][0] = 0;
    m[2][1] = 1;
    m[2][2] = 4;
    return m;
}

auto buildInitialVector() -> PWP::lib::core::Vector {
    PWP::lib::core::Vector v(3);
    v[0] = 1.0;
    v[1] = 1.0;
    v[2] = 1.0;
    return v;
}

} // namespace

TEST_CASE("PowerMethod::calculateRegular") {
    const double thresholdValue = 1e-6;
    PWP::lib::core::Matrix matrix = buildTestMatrix();
    PWP::lib::core::Vector initial = buildInitialVector();

    SUBCASE("converge para o autovalor dominante") {
        auto [eigenValue, eigenVector] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
                matrix, initial, thresholdValue);

        CHECK(eigenValue == doctest::Approx(4.0 + std::sqrt(2.0)).epsilon(thresholdValue));
    }

    SUBCASE("autovetor retornado é normalizado") {
        auto [eigenValue, eigenVector] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
                matrix, initial, thresholdValue);

        double normSquared = 0.0;
        for (int i = 0; i < 3; ++i) {
            normSquared += eigenVector[i] * eigenVector[i];
        }

        CHECK(std::sqrt(normSquared) == doctest::Approx(1.0).epsilon(1e-9));
    }
}

TEST_CASE("PowerMethod::calculateInverse") {
    const double thresholdValue = 1e-6;
    PWP::lib::core::Matrix matrix = buildTestMatrix();
    PWP::lib::core::Vector initial = buildInitialVector();
    auto solver = std::make_shared<
        PWP::lib::numeric_methods::linear_systems::direct_methods::GaussElimination>();

    SUBCASE("converge para o autovalor de menor módulo") {
        auto [eigenValue, eigenVector] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateInverse(
                matrix, initial, thresholdValue, solver);

        CHECK(eigenValue == doctest::Approx(4.0 - std::sqrt(2.0)).epsilon(thresholdValue));
    }
}

TEST_CASE("PowerMethod::calculateShifted") {
    const double thresholdValue = 1e-6;
    PWP::lib::core::Matrix matrix = buildTestMatrix();
    PWP::lib::core::Vector initial = buildInitialVector();

    SUBCASE("shift desloca espectro e converge para o autovalor mais distante dele") {
        const double shiftValue = 3.0;
        auto [eigenValue, eigenVector] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateShifted(
                matrix, initial, thresholdValue, shiftValue);
        CHECK(eigenValue == doctest::Approx(4.0 + std::sqrt(2.0)).epsilon(thresholdValue));
    }

    SUBCASE("shift zero se comporta como o regular") {
        auto [eigenValueShifted, vectorShifted] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateShifted(
                matrix, initial, thresholdValue, 0.0);
        auto [eigenValueRegular, vectorRegular] =
            PWP::lib::numeric_methods::eigenvalue_problems::PowerMethod::calculateRegular(
                matrix, initial, thresholdValue);

        CHECK(eigenValueShifted == doctest::Approx(eigenValueRegular).epsilon(1e-9));
    }
}