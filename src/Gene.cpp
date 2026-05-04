#include "Gene.hpp"

Gene::Gene(int length) : m_length(length)
{
    m_dna.resize(m_length);
    m_wwidth = 8 * sizeof(GeneWord);
    m_wnum = m_length / m_wwidth;
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

void Gene::decode(GeneWord (&targ)[5])
{
    GeneWord word;

    for (int i = 0; i < 5; i++)
    {
        word = 0;
        for (int j = 15; j >= 0; j--)
        {
            word = (word << 1) | m_dna[16 * i + j];
        }
        targ[i] = word;
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