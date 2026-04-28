#include <catch2/catch_test_macros.hpp>

#include <Gene.hpp>

TEST_CASE("simple test case retrieving the correct length of the Gene","[Gene]") {
    Gene testgene(80);

    REQUIRE(testgene.length() == 80)
}