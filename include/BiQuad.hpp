#include "Filter.hpp"

class BiQuad: public Filter
{
public:
    void process(double sample);
    void load(Stage desc);
};