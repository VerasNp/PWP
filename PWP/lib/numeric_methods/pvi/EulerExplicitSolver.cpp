#include "pvi/EulerExplicitSolver.hpp"

auto PWP::lib::numeric_methods::pvi::EulerExplicitSolver::solve(const ODEFunction &F,
                                                                const State &S0, double t0,
                                                                double dt, int steps) const
    -> std::vector<State> {
    std::vector<State> states;
    states.reserve(steps + 1);
    states.push_back(S0);
    double t = t0;
    for (int i = 0; i < steps; ++i) {
        const State &Si = states.back();
        states.push_back(Si + dt * F(Si, t));
        t += dt;
    }
    return states;
}