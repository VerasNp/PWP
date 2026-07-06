#pragma once

namespace PWP::lib::numeric_methods::derivate {
enum class DerivativeOrder { First, Second, Third, Fourth };
enum class ErrorOrder { O_h, O_h2, O_h3, O_h4 };
enum class MethodType { Forward, Backward, Central };
} // namespace PWP::lib::numeric_methods::derivate