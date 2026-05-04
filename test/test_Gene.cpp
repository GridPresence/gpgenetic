#include <catch2/catch_test_macros.hpp>

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
    vector<GeneWord> vals;
    int clen;

    SECTION("Set 1 bit in each word", "[Gene]")
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
        clen = vals.size();
        REQUIRE(clen == CLEN);

        for (int i = 0; i < clen; i++)
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
        clen = vals.size();
        REQUIRE(clen == CLEN);

        for (int i = 0; i < clen; i++)
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
        clen = vals.size();
        REQUIRE(clen == CLEN);
        for (int i = 0; i < clen; i++)
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
        clen = vals.size();
        REQUIRE(clen == CLEN);
        for (int i = 0; i < clen; i++)
        {
            REQUIRE(vals[i] == 0xaaaa);
        }

        for (int m = 0; m < testgene.length(); m++)
        {
            testgene.toggle(m);
        }
        testgene.decode(vals);
        clen = vals.size();
        REQUIRE(clen == CLEN);
        for (int i = 0; i < clen; i++)
        {
            REQUIRE(vals[i] == 0x5555);
        }
    }
};

TEST_CASE("Bitwise Gene manipulations", "[Gene]")
{
    vector<GeneWord> vals;
    int clen;

    Gene gene55(GLEN);
    gene55.flush();
    for (int m = 0; m < gene55.length(); m++)
    {
        if (m % 2 == 0)
        {
            gene55.toggle(m);
        }
    }
    gene55.decode(vals);
    clen = vals.size();
    REQUIRE(clen == CLEN);
    for (int i = 0; i < clen; i++)
    {
        REQUIRE(vals[i] == 0x5555);
    }

    Gene geneaa(GLEN);
    geneaa.flush();
    for (int m = 0; m < geneaa.length(); m++)
    {
        if (m % 2 == 1)
        {
            geneaa.toggle(m);
        }
    }
    geneaa.decode(vals);
    clen = vals.size();
    REQUIRE(clen == CLEN);
    for (int i = 0; i < clen; i++)
    {
        REQUIRE(vals[i] == 0xaaaa);
    }

    REQUIRE(gene55.bits_in_common(geneaa) == 0);
    REQUIRE(geneaa.bits_in_common(gene55) == 0);

    Gene child(geneaa, gene55);
    REQUIRE((child.bits_in_common(geneaa) + child.bits_in_common(gene55)) == 40)
};