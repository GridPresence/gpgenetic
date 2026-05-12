#include <vector>

using namespace std;

using Stage = vector<double>;
using Coefficients = vector<Stage*>;

class Filter
{
protected:
    Filter* m_next = nullptr;
    double m_result = 0.0;

public:
    virtual void process(double sample) = 0;

    double result();
    void attach(Filter* stage);
};


inline double Filter::result()
{
    return m_result;
};

inline void Filter::attach(Filter* stage)
{
    m_next = stage;
};