#include <vector>

using namespace std;

using GeneWord = unsigned short int;

class Gene
{
private:
    static const int m_wwidth = 8 * sizeof(GeneWord);

    vector<int> m_dna;
    int m_length = 0;

    int m_wnum = 0;

public:
    Gene(int length);
    Gene(Gene &prnt1, Gene &prnt2);

    ~Gene();

    int length();

    void decode(vector<GeneWord> &targ);

    void set(int idx);
    void unset(int idx);
    void toggle(int idx);
    int &operator[](int idx);

    void flush();
    void fill();

    int bits_in_common(Gene &src);

private:
    void rescale();
};

inline void Gene::set(int idx)
{
    m_dna[idx] = 1;
};

inline void Gene::unset(int idx)
{
    m_dna[idx] = 0;
};

inline void Gene::toggle(int idx)
{
    m_dna[idx] = m_dna[idx] ^ 0x0001;
};

inline int &Gene::operator[](int idx)
{
    return m_dna[idx];
}

inline void Gene::rescale()
{
    m_dna.resize(m_length);
    m_wnum = m_dna.size() / m_wwidth;
}