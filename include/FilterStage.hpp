#include <vector>

using Coefficients = std::vector<double>;

class FilterStage
{
private:
public:
    virtual double process(double sample) = 0;
    virtual void load(Coefficients& coeffs) = 0;
};