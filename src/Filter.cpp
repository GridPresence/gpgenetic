#include "Filter.hpp"

Filter::Filter(int stages)
{
    m_limit = stages;
    m_count = 0;
};

void Filter::attach(FilterStage *stage)
{
    if (m_stages.size() < m_limit)
    {
        m_stages.push_back(stage);
    }
};

double Filter::process(double sample)
{
    int steps = m_stages.size();
    double retval = 0.0;

    for (int i = 0; i < steps; i++)
    {
        retval = m_stages[i]->process(retval);
    }
    return retval;
};
