#pragma once

#include "pvi/State.hpp"
namespace PWP::lib::numeric_methods::pvi::utils {
inline auto iterateToConvergence(State initialGuess,
                                 const std::function<State(const State &)> &update,
                                 double tolerance, int maxIterations) -> State {
    State guess = std::move(initialGuess);
    for (int iter = 0; iter < maxIterations; ++iter) {
        State updated = update(guess);
        double diff = relativeDifference(updated, guess);
        guess = std::move(updated);
        if (diff < tolerance) break;
    }
    return guess;
}
} // namespace PWP::lib::numeric_methods::pvi::utils