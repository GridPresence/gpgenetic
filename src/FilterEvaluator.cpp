#include "FilterEvaluator.hpp"

double FilterEvaluator::fitness(Gene& src, Context& ctxt)
{
    src.decode(m_vals);
}