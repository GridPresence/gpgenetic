#include "BiQuad.hpp"

double BiQuad::process(double in)
{
    double out = in * b0 + z1;
    z1 = in * b1 + z2 - a1 * out;
    z2 = in * b2 - a2 * out;
    return out;
};

BiQuad::BiQuad(Coefficients& coeffs)
{
    z1 = 0.0;
    z2 = 0.0;
    if (coeffs.size() == 5)
    {
        a1 = coeffs[0];
        a2 = coeffs[1];
        b0 = coeffs[2];
        b1 = coeffs[3];
        b2 = coeffs[4];
    }
};