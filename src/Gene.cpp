#include "Gene.hpp"
#include "Random.hpp"

using Random = effolkronium::random_static;

Gene::Gene(int length) : m_length(length)
{
    rescale();
};

Gene::Gene(Gene &prnt1, Gene &prnt2)
{
    auto fptp = Random::get(1, 2);
    if (fptp == 1)
    {
        m_length = prnt2.length();
        rescale();
        auto val = Random::get(1, m_length - 2);
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
        m_length = prnt1.length();
        rescale();
        auto val = Random::get(1, m_length - 2);
        for (int i = 0; i < val; i++)
        {
            m_dna[i] = prnt2[i];
        }
        for (int i = val; i < m_length; i++)
        {
            m_dna[i] = prnt1[i];
        }
    }
};

Gene::~Gene()
{
    m_dna.clear();
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
    // For each word
    for (int i = 0; i < m_wnum; i++)
    {
        word = 0;
        // For each bit in msb->lsb order
        for (int j = m_wwidth; j >= 0; j--)
        {
            word = (word << 1) | m_dna[m_wwidth * i + j];
        }
        // Push the word onto the bottom of the output list
        targ.push_back(word);
    }
};

int Gene::bits_in_common(Gene &src)
{
    int retval = 0;
    // For every bit in each Gene
    for (int i = 0; i < m_length; i++)
    {
        // Compare and count
        if (m_dna[i] == src[i])
        {
            retval++;
        }
    }
    return retval;
}

void Gene::mutate(float probability)
{
    // Throw of the die
    auto check = Random::get(0.f, 1.f);
    // If it's a valid mutation event
    if (check <= probability)
    {
        // Arbitrarily toggle a random bit
        auto bitidx = Random::get(0, m_length - 1);
        toggle(bitidx);
    }
};

void Gene::mutate(void)
{
    // Shortform default 1% probability
    mutate(0.01);
};
