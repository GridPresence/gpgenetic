#include <vector>

using namespace std;

using GeneWord = unsigned short int;

class Gene
{
private:
    vector<int> m_dna;
    int m_length = 0;
    int m_wwidth = 8 * sizeof(GeneWord);
    int m_wnum = m_length / m_wwidth;

public:
    Gene(int length);
    ~Gene();

    int length();
    void decode(GeneWord (&targ)[5]);
    void decode(vector<GeneWord> &targ);

    void set(int idx);
    void unset(int idx);
    void toggle(int idx);

    void flush();
    void fill();
};

inline void Gene::set(int idx)
{
    m_dna.at(idx) = 1;
};

inline void Gene::unset(int idx)
{
    m_dna.at(idx) = 0;
};

inline void Gene::toggle(int idx)
{
    m_dna[idx] = m_dna[idx] ^ 0x0001;
};