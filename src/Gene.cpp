#include "Gene.hpp"
#include "Random.hpp"

using Random = effolkronium::random_static;

Gene::Gene(int length) : m_length(length)
{
    rescale();
};

Gene::Gene(Gene &prnt1, Gene &prnt2)
{
    if (prnt1.length() == prnt2.length())
    {
        m_length = prnt1.length();
        rescale();
        auto val = Random::get(1, m_length - 2);
        auto fptp = Random::get(1, 2);
        if (fptp == 1)
        {
            for (int i = 0; i < val; i++)
            {
                m_dna[i] = prnt1[i];
            }
            for (int i = val; i < m_length; i++)
            {
                m_dna[i] = prnt2[i];
            }
        }
        else
        {
            for (int i = 0; i < val; i++)
            {
                m_dna[i] = prnt2[i];
            }
            for (int i = val; i < m_length; i++)
            {
                m_dna[i] = prnt1[i];
            }
        }
    }
};

Gene::~Gene()
{
    m_dna.clear();
};

int Gene::length()
{
    return m_length;
};

void Gene::flush()
{
    for (int i = 0; i < m_length; i++)
    {
        unset(i);
    }
};

void Gene::fill()
{
    for (int i = 0; i < m_length; i++)
    {
        set(i);
    }
};

void Gene::decode(vector<GeneWord> &targ)
{
    GeneWord word;

    // Empty the vector
    targ.clear();

    for (int i = 0; i < m_wnum; i++)
    {
        word = 0;
        for (int j = m_wwidth; j >= 0; j--)
        {
            word = (word << 1) | m_dna[m_wwidth * i + j];
        }
        targ.push_back(word);
    }
};

int Gene::bits_in_common(Gene &src)
{
    int retval = 0;

    for (int i = 0; i < m_length; i++)
    {
        if (m_dna[i] == src[i])
        {
            retval++;
        }
    }
    return retval;
}
