#include <fstream>
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <vector>

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
        for (SizeType i = 0; i < d["freqs"].Size(); i++)
        {
            frequencies.push_back(d["freqs"][i].GetDouble());
        }
        for (SizeType i = 0; i < d["bode"].Size(); i++)
        {
            decibels.push_back(d["bode"][i].GetDouble());
        }
        if (decibels.size() != frequencies.size())
        {
            throw ContextException("Unequal datapoints in bode specification");
        }
    }
};