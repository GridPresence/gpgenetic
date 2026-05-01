#include <catch2/catch_test_macros.hpp>

#include "Gene.hpp"

#define LOCBYTE 8
#define CWIDTH sizeof(unsigned short int) * LOCBYTE
#define CLEN 5
#define GLEN CWIDTH *CLEN

TEST_CASE("Basic Gene operations", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    REQUIRE(testgene.length() == 80);

    testgene.clear();
    testgene.decode(vals);
    for (int i = 0; i < CLEN; i++)
    {
        REQUIRE(vals[i] == 0);
    }
    testgene.fill();
    testgene.decode(vals);
    for (int i = 0; i < CLEN; i++)
    {
        REQUIRE(vals[i] == 65535);
    }
};