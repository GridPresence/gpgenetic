#include <catch2/catch_test_macros.hpp>

#include "Gene.hpp"

#define LOCBYTE 8
#define CWIDTH sizeof(unsigned short int) * LOCBYTE
#define CLEN 5
#define GLEN CWIDTH *CLEN

TEST_CASE("Basic Gene manipulations", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    SECTION("Set Gene length", "[Gene]")
    {
        REQUIRE(testgene.length() == 80);
    }

    SECTION("Set Gene clear", "[Gene]")
    {
        testgene.flush();
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 0);
        }
    }

    SECTION("Set Gene fill", "[Gene]")
    {
        testgene.fill();
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 65535);
        }
    }
};