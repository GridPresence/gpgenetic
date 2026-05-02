#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "Gene.hpp"

#define LOCBYTE 8
#define CWIDTH sizeof(unsigned short int) * LOCBYTE
#define CLEN 5
#define GLEN CWIDTH *CLEN

TEST_CASE("Basic Gene full manipulations", "[Gene]")
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
            cout << i << " - " << vals[i] << "\n";
        }
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
            cout << i << " - " << vals[i] << "\n";
        }
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 65535);
        }
    }
};

TEST_CASE("Bitwise Gene manipulations", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    SECTION("Set 1 bit in first word", "[Gene]")
    {
        testgene.flush();
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            cout << i << " - " << vals[i] << "\n";
        }
        // 1
        testgene.set(0);

        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            cout << i << " - " << vals[i] << "\n";
        }
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[0] == 1);
        }
    }
};