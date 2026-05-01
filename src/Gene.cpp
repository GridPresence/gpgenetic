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

void Gene::clear()
{
    for (int i = 0; i < m_length; i++)
    {
        this->unset(i);
    }
};

void Gene::fill()
{
    for (int i = 0; i < m_length; i++)
    {
        this->set(i);
    }
};

void Gene::decode(unsigned short int (&targ)[5])
{
    unsigned short int word;
    bool bit;

    for (int i = 0; i < 5; i++)
    {
        word = 0;
        for (int j = 0; j < 16; j++)
        {
            bit = (bool)(m_dna->at(16 * i + j));
            word = bit << 1;
        }
        targ[i] = word;
    }
};