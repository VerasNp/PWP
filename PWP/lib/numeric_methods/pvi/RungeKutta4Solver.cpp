#include "pvi/RungeKutta4Solver.hpp"

auto PWP::lib::numeric_methods::pvi::RungeKutta4Solver::solve(const ODEFunction &F, const State &S0,
                                                              double t0, double dt, int steps) const
    -> std::vector<State> {
    std::vector<State> states;
    states.reserve(steps + 1);
    states.push_back(S0);
    double t = t0;
    for (int i = 0; i < steps; ++i) {
        const State &Si = states.back();
        State F1 = F(Si, t);
        State S2 = Si + (dt / 2.0) * F1;
        State F2 = F(S2, t + dt / 2.0);
        State S3 = Si + (dt / 2.0) * F2;
        State F3 = F(S3, t + dt / 2.0);
        State S4 = Si + dt * F3;
        State F4 = F(S4, t + dt);

        states.push_back(Si + (dt / 6.0) * (F1 + 2.0 * F2 + 2.0 * F3 + F4));
        t += dt;
    }
    return states;
}