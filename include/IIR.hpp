#include "Filter.hpp"
#include "BiQuad.hpp"

class IIR: public Filter
{
private:
    vector<BiQuad*> m_bqstages;

public:
    void process(double sample);
    void load(Coefficients desc);


};