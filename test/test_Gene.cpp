#include <catch2/catch_test_macros.hpp>

#include "Gene.hpp"

#define LOCBYTE 8
#define CWIDTH sizeof(unsigned short int) * LOCBYTE
#define CLEN 5
#define GLEN CWIDTH *CLEN

TEST_CASE("Basic Gene length", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    REQUIRE(testgene.length() == 80);
};

TEST_CASE("Basic Gene clear", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    testgene.clear();
    testgene.decode(vals);
    for (int i = 0; i < CLEN; i++)
    {
        REQUIRE(vals[i] == 0);
    }
};

TEST_CASE("Basic Gene fill", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    testgene.fill();
    testgene.decode(vals);
    for (int i = 0; i < CLEN; i++)
    {
        REQUIRE(vals[i] == 65535);
    }
};