#include <fstream>
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <vector>
#include <cmath>

#include "Context.hpp"

using namespace rapidjson;

bool Context::IsValid(Document &doc)
{
    bool retval = true;
    if (doc.HasMember("fsamp"))
    {
        retval = doc["fsamp"].IsNumber();
        if (!retval) throw ContextException("fsamp is not a Number");
    }
    if (!retval) throw ContextException("fsamp is not present");

    if (retval && doc.HasMember("stages"))
    {
        retval = doc["stages"].IsNumber();
        if (!retval) throw ContextException("stages is not a Number");
    }
    if (!retval) throw ContextException("stages is not present");

    if (retval && doc.HasMember("freqs"))
    {
        retval = doc["freqs"].IsArray();
        if (!retval) throw ContextException("freqs is not an Array");
    }
    if (!retval) throw ContextException("freqs is not present");

    if (retval && doc.HasMember("bode"))
    {
        retval = doc["bode"].IsArray();
        if (!retval) throw ContextException("bode is not an Array");
    }
    if (!retval) throw ContextException("bode is not present");

    return retval;
}

Context::Context(std::string &config)
{
    FILE *fp = fopen(config.c_str(), "r");

    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document d;
    d.ParseStream(is);
    if (this->IsValid(d))
    {
        m_sample_rate = d["fsamp"].GetDouble();
        m_stages = d["stages"].GetInt();
        for (SizeType i = 0; i < d["freqs"].Size(); i++)
        {
            m_frequencies.push_back(d["freqs"][i].GetDouble());
        }
        for (SizeType i = 0; i < d["bode"].Size(); i++)
        {
            m_decibels.push_back(d["bode"][i].GetDouble());
        }
        if (m_decibels.size() != m_frequencies.size())
        {
            throw ContextException("Unequal datapoints in bode specification");
        }
    }
    this->linearise_bode();
};

void Context::linearise_bode()
{
    int scope = m_frequencies.size();
    for (int i = 0; i < scope; i++)
    {
        m_normalised_frequencies.push_back(2.0 * M_PI * m_frequencies[i] / m_sample_rate);
        m_linear_responses.push_back(pow(10.0, (0.05 * m_decibels[i])));
    }
};

void Context::enbode()
{

};