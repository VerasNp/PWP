#include "GaussElimination.hpp"
#include "Vector.hpp"
#include <cstdlib>
#include <utility>

auto PWP::lib::numeric_methods::linear_systems::direct_methods::GaussElimination::solve(
    core::Matrix &coefficientMatrix, core::Vector &constantVector) -> core::Vector {
    int n = coefficientMatrix.getRows();
    core::Vector variableVector(n);
    for (int i = 0; i < n; i++) {
        int pivotRow = i;
        for (int j = i + 1; j < n; j++) {
            if (std::abs(coefficientMatrix[j][i]) > std::abs(coefficientMatrix[pivotRow][i])) {
                pivotRow = j;
            }
        }
        if (pivotRow != i) {
            coefficientMatrix.swapRows(i, pivotRow);
            std::swap(constantVector[i], constantVector[pivotRow]);
        }
        for (int j = i + 1; j < n; j++) {
            double factor = coefficientMatrix[j][i] / coefficientMatrix[i][i];
            for (int k = i; k < n; k++) {
                coefficientMatrix[j][k] -= factor * coefficientMatrix[i][k];
            }
            constantVector[j] -= factor * constantVector[i];
        }
    }
    core::Vector solution(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = constantVector[i];
        for (int j = i + 1; j < n; j++) {
            sum -= coefficientMatrix[i][j] * solution[j];
        }
        solution[i] = sum / coefficientMatrix[i][i];
    }
    return solution;
}