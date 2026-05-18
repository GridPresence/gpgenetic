#include "FilterStage.hpp"

class BiQuad : public FilterStage
{
private:
    double a1, a2;
    double b0, b1, b2;
    double z1, z2;

public:
    BiQuad(Coefficients& spec);
    double process(double sample);
};