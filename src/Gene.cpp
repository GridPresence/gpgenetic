#include "Gene.hpp"

Gene::Gene(int length) : m_length(length)
{
    m_dna = new vector<int>[m_length];
};

Gene::~Gene()
{
    delete[] m_dna;
    m_dna = nullptr;
};

int Gene::length()
{
    return m_length;
};

void Gene::decode(unsigned short int (&targ)[5])
{
    for (int i = 0; i < 5; i++)
    {
        targ[i] = i;
    }
};