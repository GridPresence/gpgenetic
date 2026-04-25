#include "Gene.hpp"

Gene::Gene(int length):
m_length(length)
{
    m_dna = new vector<int>[m_length];
};

Gene::~Gene()
{
    delete [] m_dna;
    m_dna = nullptr;
};