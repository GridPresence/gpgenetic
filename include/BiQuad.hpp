#include "FilterStage.hpp"

class BiQuad : public FilterStage
{
private:
    double m_a1 = 0.0;
    double m_a2 = 0.0;
    double m_b0 = 0.0;
    double m_b1 = 0.0;
    double m_b2 = 0.0;
    double m_z1 = 0.0;
    double m_z2 = 0.0;

public:
    BiQuad(Coefficients& spec);
    double process(double sample);
    double response(double rads);
};