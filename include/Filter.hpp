#include <vector>
#include "FilterStage.hpp"

using namespace std;

class Filter
{
private:
    int m_limit;
    vector<FilterStage *> m_stages;

public:
    void Filter(int stages);
    double process(double sample);

    void attach(FilterStage *stage);
};
