#include "Evaluator.hpp"

#include <vector>

using namespace std;

class FilterEvaluator: public Evaluator
{
private:
    vector<GeneWord> m_vals;

public:
    FilterEvaluator();
    double fitness(Gene& src, Context& ctxt);
};