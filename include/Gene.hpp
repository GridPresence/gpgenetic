#include <vector>

using namespace std;

class Gene
{
private:
    vector<int> *m_dna = nullptr;
    int m_length = 0;

public:
    Gene(int length);
    ~Gene();

    int length();
    void decode(unsigned short int (&targ)[5]);

    void set(int idx);
    void unset(int idx);
    void toggle(int idx);

    void clear();
    void fill();
};

inline void Gene::set(int idx)
{
    m_dna->at(idx) = 1;
};

inline void Gene::unset(int idx)
{
    m_dna->at(idx) = 0;
};

inline void Gene::toggle(int idx)
{
    m_dna->at(idx) = ~(m_dna->at(idx));
};