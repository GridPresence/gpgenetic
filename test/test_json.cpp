#include <catch2/catch_test_macros.hpp>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>

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
        REQUIRE(d["fsamp"].IsInt());
        REQUIRE(d["fsamp"].GetInt() == 44100);

    }

    fclose(fp);
};