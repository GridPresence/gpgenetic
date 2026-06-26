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
    }
    if (retval && doc.HasMember("stages"))
    {
        retval = doc["stages"].IsNumber();
    }
    if (retval && doc.HasMember("freqs"))
    {
    }
    else
    {
        retval = false;
    }
    if (retval && doc.HasMember("bode"))
    {
    }
    else
    {
        retval = false;
    }

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
    }
};