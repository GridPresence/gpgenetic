#include <vector>

using namespace std;

class Gene
{
    private:
        vector<int>* m_dna = nullptr;
        int m_length = 0;

    public:
        Gene(int length);
        ~Gene();

        int length();
};