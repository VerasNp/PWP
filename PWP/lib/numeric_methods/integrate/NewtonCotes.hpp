#pragma once

#include "integrate/Stencil.hpp"

namespace PWP::lib::numeric_methods::integrate::NewtonCotes {

namespace Closed {
    const Stencil Degree1 = {{1, 1},            {0, 1},               2};
    const Stencil Degree2 = {{1, 4, 1},         {0, 0.5, 1},          6};
    const Stencil Degree3 = {{1, 3, 3, 1},      {0, 1./3, 2./3, 1},   8};
    const Stencil Degree4 = {{7, 32, 12, 32, 7},{0, .25, .5, .75, 1}, 90};
}

namespace Open {
    const Stencil Degree1 = {{1, 1},                  {1./3, 2./3},                      2};
    const Stencil Degree2 = {{2, -1, 2},              {.25, .5, .75},                    3};
    const Stencil Degree3 = {{11, 1, 1, 11},          {.2, .4, .6, .8},                 24};
    const Stencil Degree4 = {{11, -14, 26, -14, 11},  {1./6, 2./6, .5, 4./6, 5./6},    20};
}

} // namespace PWP::lib::numeric_methods::integrate::NewtonCotes
