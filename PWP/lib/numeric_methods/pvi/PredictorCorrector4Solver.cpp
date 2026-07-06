#include "pvi/PredictorCorrector4Solver.hpp"
#include "pvi/RungeKutta4Solver.hpp"
#include "pvi/utils/FixedPointIteration.hpp"
#include <stdexcept>

PWP::lib::numeric_methods::pvi::PredictorCorrector4Solver::PredictorCorrector4Solver(
    double tolerance, int maxIterations)
    : tolerance_(tolerance), maxIterations_(maxIterations) {}

auto PWP::lib::numeric_methods::pvi::PredictorCorrector4Solver::solve(const ODEFunction &F,
                                                                      const State &S0, double t0,
                                                                      double dt, int steps) const
    -> std::vector<State> {
    if (steps < 3) {
        throw std::invalid_argument(
            "PredictorCorrector4Solver exige pelo menos 3 passos para inicialização via RK4");
    }

    std::vector<State> states;
    states.reserve(steps + 1);
    states.push_back(S0);

    RungeKutta4Solver rk4;
    auto initial = rk4.solve(F, S0, t0, dt, 3);
    for (size_t i = 1; i < initial.size(); ++i)
        states.push_back(initial[i]);

    for (int i = 3; i < steps; ++i) {
        const State &Si = states[i], &Sim1 = states[i - 1], &Sim2 = states[i - 2],
                    &Sim3 = states[i - 3];
        double ti = t0 + i * dt, tim1 = t0 + (i - 1) * dt, tim2 = t0 + (i - 2) * dt,
               tim3 = t0 + (i - 3) * dt;
        double tNext = ti + dt;

        State Fi = F(Si, ti), Fim1 = F(Sim1, tim1), Fim2 = F(Sim2, tim2), Fim3 = F(Sim3, tim3);

        State predicted = Si + (dt / 24.0) * (55.0 * Fi - 59.0 * Fim1 + 37.0 * Fim2 - 9.0 * Fim3);

        State corrected = PWP::lib::numeric_methods::pvi::utils::iterateToConvergence(
            std::move(predicted),
            [&](const State &guess) {
                State FNext = F(guess, tNext);
                return Si + (dt / 24.0) * (9.0 * FNext + 19.0 * Fi - 5.0 * Fim1 + Fim2);
            },
            tolerance_, maxIterations_);

        states.push_back(corrected);
    }
    return states;
}