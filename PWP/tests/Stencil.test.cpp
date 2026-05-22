#include "derivate/stencil/Stencil.hpp"
#include "derivate/DerivateBase.hpp"
#include "doctest.h"

TEST_CASE("Stencil - Orders") {
    using namespace PWP::lib::numeric_methods::derivate::stencil;
    Stencil stencil = {.derivateOrder = PWP::lib::numeric_methods::derivate::DerivativeOrder::First,
                       .errorOrder = PWP::lib::numeric_methods::derivate::ErrorOrder::O_h,
                       .coefficient = {1, -1},
                       .offset = {1, 0},
                       .denominator = 1.0,
                       .denominator_power = 1};
    CHECK(stencil.derivateOrder == PWP::lib::numeric_methods::derivate::DerivativeOrder::First);
    CHECK(stencil.errorOrder == PWP::lib::numeric_methods::derivate::ErrorOrder::O_h);
}

TEST_CASE("Stencil - Coefficients") {
    using namespace PWP::lib::numeric_methods::derivate::stencil;
    Stencil stencil = {.derivateOrder = PWP::lib::numeric_methods::derivate::DerivativeOrder::First,
                       .errorOrder = PWP::lib::numeric_methods::derivate::ErrorOrder::O_h,
                       .coefficient = {1, -1},
                       .offset = {1, 0},
                       .denominator = 1.0,
                       .denominator_power = 1};
    CHECK(stencil.coefficient.size() == 2);
    CHECK(stencil.coefficient[0] == 1);
    CHECK(stencil.coefficient[1] == -1);
}

TEST_CASE("Stencil - Offsets and Denominator") {
    using namespace PWP::lib::numeric_methods::derivate::stencil;
    Stencil stencil = {.derivateOrder = PWP::lib::numeric_methods::derivate::DerivativeOrder::First,
                       .errorOrder = PWP::lib::numeric_methods::derivate::ErrorOrder::O_h,
                       .coefficient = {1, -1},
                       .offset = {1, 0},
                       .denominator = 1.0,
                       .denominator_power = 1};
    CHECK(stencil.offset.size() == 2);
    CHECK(stencil.offset[0] == 1);
    CHECK(stencil.offset[1] == 0);
    CHECK(stencil.denominator == 1.0);
    CHECK(stencil.denominator_power == 1);
}