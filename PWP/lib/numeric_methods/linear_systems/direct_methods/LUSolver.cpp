#include "LUSolver.hpp"
#include "Vector.hpp"
#include "matrices_factorization/LUDecomposition.hpp"
#include <sys/types.h>

auto PWP::lib::numeric_methods::linear_systems::direct_methods::LUSolver::solve(
    core::Matrix &coefficientMatrix, core::Vector &constantVector) -> core::Vector {
    core::Vector variableVector(constantVector.getSize());
    matrices_factorization::LUDecomposition luDecomp(coefficientMatrix);
    luDecomp.execute();

    int ip, ii;
    for (uint i = 0; i < coefficientMatrix.getRows(); i++) {
        variableVector[i] = constantVector[i];
    }
    for (uint i = 0; i < coefficientMatrix.getRows(); i++) {
        ip = luDecomp.getPermutation()[i];
        double sum = variableVector[ip];
        variableVector[ip] = variableVector[i];
        if (ii != 0) {
            for (uint j = ii - 1; j < i; j++) {
                sum -= luDecomp.getLUDecomposition()[i][j] * variableVector[j];
            }
        } else if (sum != 0) {
            ii = i + 1;
        }
        variableVector[i] = sum;
    }
    for (uint i = coefficientMatrix.getRows() - 1; i >= 0; i--) {
        double sum = variableVector[i];
        for (uint j = i - 1; j < coefficientMatrix.getColumns(); j++) {
            sum -= luDecomp.getLUDecomposition()[i - 1][j] * variableVector[j];
        }
        variableVector[i] = sum / luDecomp.getLUDecomposition()[i][i];
    }
    return variableVector;
}