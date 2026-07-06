#pragma once

#include "pvi/State.hpp"
#include <vector>

namespace PWP::lib::numeric_methods::pvi {
class ODESolver {
  public:
    virtual ~ODESolver() = default;
    [[nodiscard]] virtual auto solve(const ODEFunction &F, const State &S0, double t0, double dt,
                                     int steps) const -> std::vector<State> = 0;
};

} // namespace PWP::lib::numeric_methods::pvi