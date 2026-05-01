#include "Gene.hpp"

Gene::Gene(int length) : m_length(length)
{
    m_dna.resize(m_length);
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

void Gene::decode(unsigned short int (&targ)[5])
{
    unsigned short int word;

    for (int i = 0; i < 5; i++)
    {
        word = 0;
        for (int j = 0; j < 16; j++)
        {
            word = (word << 1) | m_dna[16 * i + j];
        }
        targ[i] = word;
    }
};