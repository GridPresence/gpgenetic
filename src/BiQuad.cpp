#include "BiQuad.hpp"
#include <complex>

using namespace std;

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

double BiQuad::response(double freq)
{
    double retval = 0.0;
    double w = 2.0 * M_PI * freq / m_fsamp;
    double w2 = 2.0 * w;
    complex<double> num = complex<double>(m_b0 + m_b1*cos(w) + m_b2*cos(w2),-m_b1*sin(w)-m_b2*sin(w2));
    complex<double> den = complex<double>(1.0 - m_a1*cos(w) - m_a2*cos(w2),-m_a1*sin(w)-m_a2*sin(w2));
    complex<double> resp = num / den;
    retval = 20.0 * log10(abs(resp));
    return retval;
}