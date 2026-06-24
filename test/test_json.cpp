#include <catch2/catch_test_macros.hpp>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <vector>

using namespace rapidjson;

TEST_CASE("Basic JSON file read and parse", "[Json]")
{
    FILE *fp = fopen("test01.json", "r");

    char readBuffer[65536];
    FileReadStream is(fp, readBuffer, sizeof(readBuffer));

    Document d;
    d.ParseStream(is);

    SECTION("Get JSON elements", "[Json]")
    {
        REQUIRE(d.HasMember("fsamp"));
        REQUIRE(d["fsamp"].IsNumber());
        REQUIRE(d["fsamp"].GetDouble() == 44100);
        
        REQUIRE(d.HasMember("freqs"));
        REQUIRE(d["freqs"].IsArray());

        REQUIRE(d.HasMember("bode"));
        REQUIRE(d["bode"].IsArray());

        REQUIRE(d["freqs"].Size() == d["bode"].Size());

        std::vector<double> freeks;

        for (SizeType i = 0; i < d["freqs"].Size(); i++)
        {
            freeks.push_back(d["freqs"][i].GetDouble());
        }
        REQUIRE(freeks[0] == 1);
        REQUIRE(freeks[1] == 10);
        REQUIRE(freeks[2] == 100);
        REQUIRE(freeks[3] == 400);
        REQUIRE(freeks[4] == 1000);
        REQUIRE(freeks[5] == 2500);
        REQUIRE(freeks[6] == 4000);
        REQUIRE(freeks[7] == 10000);
        REQUIRE(freeks[8] == 20000);

        std::vector<double> boad;

        for (SizeType i = 0; i < d["bode"].Size(); i++)
        {
            boad.push_back(d["bode"][i].GetDouble());
        }
        REQUIRE(boad[0] == -100);
        REQUIRE(boad[1] == -100);
        REQUIRE(boad[2] == -50);
        REQUIRE(boad[3] == -3);
        REQUIRE(boad[4] == 0);
        REQUIRE(boad[5] == 0);
        REQUIRE(boad[6] == -3);
        REQUIRE(boad[7] == -20);
        REQUIRE(boad[8] == -30);
    }

    fclose(fp);
};