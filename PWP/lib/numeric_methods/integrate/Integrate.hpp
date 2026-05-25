namespace PWP::lib::numeric_methods::integrate {
class Integrate {
  public:
    double tol = 1e-6;
    Integrate(int aValue, int bValue, double tolerance)
        : aValue_(aValue), bValue_(bValue), tolerance_(tolerance) {};
    auto openTrapezoid(double (*func)(double)) -> double {
        double deltaX = (this->bValue_ - this->aValue_);
        double result = func(this->aValue_) + func(this->bValue_);
        while (result > tol)
    }

  private:
    int aValue_;
    int bValue_;
    double tolerance_;
};
} // namespace PWP::lib::numeric_methods::integrate