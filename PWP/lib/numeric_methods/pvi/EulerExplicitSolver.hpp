#include "pvi/ODESolver.hpp"
namespace PWP::lib::numeric_methods::pvi {
class EulerExplicitSolver : public ODESolver {
  public:
    [[nodiscard]] auto solve(const ODEFunction &F, const State &S0, double t0, double dt,
                             int steps) const -> std::vector<State> override;
};

} // namespace PWP::lib::numeric_methods::pvi