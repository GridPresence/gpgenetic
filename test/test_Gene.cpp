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

TEST_CASE("Bitwise Gene manipulations", "[Gene]")
{
    Gene testgene(GLEN);
    unsigned short int vals[CLEN];

    SECTION("Set 1 bit in first word", "[Gene]")
    {
        testgene.flush();
        testgene.decode(vals);
        // 1
        testgene.set(0);
        // 2
        testgene.set(17);
        // 3
        testgene.set(32);
        testgene.set(33);
        // 4
        testgene.set(50);
        // 5
        testgene.set(64);
        testgene.set(66);

        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == (i + 1));
        }
    }

    SECTION("Toggle odd bits", "[Gene]")
    {
        testgene.flush();
        for (int m = 0; m < testgene.length(); m++)
        {
            if (m % 2 == 0)
            {
                testgene.toggle(m);
            }
        }
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 0x5555);
        }
    }

    SECTION("Toggle even bits", "[Gene]")
    {
        testgene.flush();
        for (int m = 0; m < testgene.length(); m++)
        {
            if (m % 2 == 1)
            {
                testgene.toggle(m);
            }
        }
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 0xaaaa);
        }
    }

    SECTION("Toggle all bits", "[Gene]")
    {
        testgene.flush();
        for (int m = 0; m < testgene.length(); m++)
        {
            if (m % 2 == 1)
            {
                testgene.toggle(m);
            }
        }
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 0xaaaa);
        }
        for (int m = 0; m < testgene.length(); m++)
        {
            testgene.toggle(m);
        }
        testgene.decode(vals);
        for (int i = 0; i < CLEN; i++)
        {
            REQUIRE(vals[i] == 0x5555);
        }
    }
};