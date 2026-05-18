#include <vector>

using Coefficients = vector<double>;

class FilterStage
{
private:
public:
    double process(double sample) = 0;
    void load(Coefficients coeffs) = 0;
};