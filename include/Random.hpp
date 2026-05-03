#include <vector>

using namespace std;

class UniformRandomDeviate
{
private:
    const long MBIG = 1000000000;
    const long MSEED = 161803398;
    const long MZ = 0;
    const float FAC = 1.0 / (float)MBIG;

public:
    UniformRandomDeviate();
};