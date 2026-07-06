#include "pvi/EulerImplicitSolver.hpp"
#include "pvi/utils/FixedPointIteration.hpp"

PWP::lib::numeric_methods::pvi::EulerImplicitSolver::EulerImplicitSolver(double tolerance,
                                                                         int maxIterations)
    : tolerance_(tolerance), maxIterations_(maxIterations) {}

auto PWP::lib::numeric_methods::pvi::EulerImplicitSolver::solve(const ODEFunction &F,
                                                                const State &S0, double t0,
                                                                double dt, int steps) const
    -> std::vector<State> {
    std::vector<State> states;
    states.reserve(steps + 1);
    states.push_back(S0);
    double t = t0;
    for (int i = 0; i < steps; ++i) {
        const State &Si = states.back();
        double tNext = t + dt;
        State initialGuess = Si + dt * F(Si, t);

        State result = PWP::lib::numeric_methods::pvi::utils::iterateToConvergence(
            std::move(initialGuess), [&](const State &guess) { return Si + dt * F(guess, tNext); },
            tolerance_, maxIterations_);

        states.push_back(result);
        t = tNext;
    }
    return states;
}