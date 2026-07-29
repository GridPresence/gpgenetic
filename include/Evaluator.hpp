#include "Gene.hpp"
#include "Context.hpp"

using namespace std;

class Evaluator
{
private:

public:
    Evaluator();
    virtual double fitness(Gene& src, Context& ctxt ) = 0;
};