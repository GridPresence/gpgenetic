#include <vector>
#include "FilterStage.hpp"

using namespace std;

class Filter
{
private:
    int m_limit;
    int m_count;
    vector<FilterStage *> m_stages;

public:
    Filter(int stages);
    double process(double sample);

    void attach(FilterStage *stage);
};
