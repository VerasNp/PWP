#include "IDerivateCreator.hpp"
namespace PWP::lib::numeric_methods::derivate {
class ForwardCreator : IDerivateCreator {
  public:
    [[nodiscard]] auto create(ErrorOrder errorOrder) const
        -> std::unique_ptr<IDerivate> override;
};
} // namespace PWP::lib::numeric_methods::derivate