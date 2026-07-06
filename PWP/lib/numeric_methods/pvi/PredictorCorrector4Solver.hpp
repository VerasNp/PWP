#pragma once

#include "pvi/ODESolver.hpp"
namespace PWP::lib::numeric_methods::pvi {
class PredictorCorrector4Solver : public ODESolver {
  public:
    explicit PredictorCorrector4Solver(double tolerance = 1e-9, int maxIterations = 50);
    [[nodiscard]] auto solve(const ODEFunction &F, const State &S0, double t0, double dt,
                             int steps) const -> std::vector<State> override;

  private:
    double tolerance_;
    int maxIterations_;
};
} // namespace PWP::lib::numeric_methods::pvi