#include "Matrix.hpp"
#include "Vector.hpp"
#include "linear_systems/ILinearSystem.hpp"
namespace PWP::lib::numeric_methods::linear_systems::direct_methods {
class LUSolver : public ILinearSystem {
  public:
    auto solve(core::Matrix &coefficientMatrix, core::Vector &constantVector)
        -> core::Vector override;

};
} // namespace PWP::lib::numeric_methods::linear_systems::direct_methods