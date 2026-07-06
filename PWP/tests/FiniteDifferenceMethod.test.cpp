#include "boundary_value_problems/FiniteDifferenceMethod.hpp"
#include "doctest.h"
#include <cmath>
#include <stdexcept>

using namespace PWP::lib::numeric_methods::boundary_value_problems;

TEST_CASE("FiniteDifferenceMethod::solve — y'' - y = 0, y(0)=0, y(1)=1") {
    // Solução exata: y(x) = sinh(x) / sinh(1)
    LinearBVP problem{
        .p = [](double) { return 0.0; },
        .q = [](double) { return -1.0; },
        .r = [](double) { return 0.0; },
        .a = 0.0,
        .b = 1.0,
        .alpha = 0.0,
        .beta = 1.0,
    };

    SUBCASE("condições de contorno são respeitadas exatamente") {
        FiniteDifferenceResult result = solve(problem, 10);
        CHECK(result.y[0] == doctest::Approx(0.0).epsilon(1e-12));
        CHECK(result.y[10] == doctest::Approx(1.0).epsilon(1e-12));
    }

    SUBCASE("converge para a solução analítica com N=100") {
        FiniteDifferenceResult result = solve(problem, 100);
        for (unsigned int i = 0; i <= 100; i++) {
            double exact = std::sinh(result.x[i]) / std::sinh(1.0);
            CHECK(result.y[i] == doctest::Approx(exact).epsilon(1e-3));
        }
    }

    SUBCASE("erro diminui com o refino da malha (convergência O(h^2))") {
        double exactAtMid = std::sinh(0.5) / std::sinh(1.0);

        FiniteDifferenceResult coarse = solve(problem, 10);
        FiniteDifferenceResult fine = solve(problem, 100);

        double errorCoarse = std::abs(coarse.y[5] - exactAtMid);
        double errorFine = std::abs(fine.y[50] - exactAtMid);

        CHECK(errorFine < errorCoarse);
        CHECK(errorFine < 1e-4);
    }
}

TEST_CASE("FiniteDifferenceMethod::solve — y'' + y' = 0, y(0)=0, y(1)=1") {
    // Solução exata: y(x) = (1 - e^{-x}) / (1 - e^{-1})
    LinearBVP problem{
        .p = [](double) { return 1.0; },
        .q = [](double) { return 0.0; },
        .r = [](double) { return 0.0; },
        .a = 0.0,
        .b = 1.0,
        .alpha = 0.0,
        .beta = 1.0,
    };

    FiniteDifferenceResult result = solve(problem, 100);
    for (unsigned int i = 0; i <= 100; i++) {
        double exact = (1.0 - std::exp(-result.x[i])) / (1.0 - std::exp(-1.0));
        CHECK(result.y[i] == doctest::Approx(exact).epsilon(1e-3));
    }
}

TEST_CASE("FiniteDifferenceMethod::solve — y'' = 6x, y(0)=0, y(1)=1") {
    // Solução exata: y(x) = x^3 (verifica termo não-homogêneo r(x))
    LinearBVP problem{
        .p = [](double) { return 0.0; },
        .q = [](double) { return 0.0; },
        .r = [](double x) { return 6.0 * x; },
        .a = 0.0,
        .b = 1.0,
        .alpha = 0.0,
        .beta = 1.0,
    };

    FiniteDifferenceResult result = solve(problem, 20);
    for (unsigned int i = 0; i <= 20; i++) {
        double exact = result.x[i] * result.x[i] * result.x[i];
        CHECK(result.y[i] == doctest::Approx(exact).epsilon(1e-6));
    }
}

TEST_CASE("FiniteDifferenceMethod::solve — N < 2 lança exceção") {
    LinearBVP problem{
        .p = [](double) { return 0.0; },
        .q = [](double) { return -1.0; },
        .r = [](double) { return 0.0; },
        .a = 0.0,
        .b = 1.0,
        .alpha = 0.0,
        .beta = 1.0,
    };

    CHECK_THROWS_AS(solve(problem, 1), std::invalid_argument);
}
