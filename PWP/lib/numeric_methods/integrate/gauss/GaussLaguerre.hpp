#pragma once

#include "integrate/GaussRule.hpp"
#include <cmath>

namespace PWP::lib::numeric_methods::integrate::GaussLaguerre {

inline const GaussRule GL2 = {
    { 2.0-std::sqrt(2.0), 2.0+std::sqrt(2.0) },
    { (2.0+std::sqrt(2.0))/4.0, (2.0-std::sqrt(2.0))/4.0 }
};

inline const GaussRule GL3 = {
    { 0.4157745567834791, 2.2942803602790417, 6.2899450829374794 },
    { 0.7110930099291730, 0.2785177335692408, 0.0103892565015861 }
};

inline const GaussRule GL4 = {
    { 0.3225476896193924, 1.7457611011583466, 4.5366202969211776, 9.3950709123011340 },
    { 0.6031541043416337, 0.3574186924377997, 0.0388879085150054, 0.0005392947055613 }
};

} // namespace PWP::lib::numeric_methods::integrate::GaussLaguerre
