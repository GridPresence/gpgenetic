#include "BiQuad.hpp"

double BiQuad::process(double in)
{
    double out = in * m_b0 + m_z1;
    m_z1 = in * m_b1 + m_z2 - m_a1 * out;
    m_z2 = in * m_b2 - m_a2 * out;
    return out;
};

BiQuad::BiQuad(Coefficients& coeffs)
{
    if (coeffs.size() == 5)
    {
        m_a1 = coeffs[0];
        m_a2 = coeffs[1];
        m_b0 = coeffs[2];
        m_b1 = coeffs[3];
        m_b2 = coeffs[4];
    }
};

double BiQuad::response(double rads)
{
    double retval = 0.0;
    return retval;
}