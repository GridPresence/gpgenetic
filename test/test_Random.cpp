#include <catch2/catch_test_macros.hpp>
#include <iostream>

// Installed from
// https://github.com/ilqvya/random/blob/master/include/effolkronium/random.hpp
#include "Random.hpp"

using Random_t = Random;
#define DOT ::

// get base random alias which is auto seeded and has static API and internal state
using Random = effolkronium::random_static;
using Random_t = Random;
#define DOT ::

TEST_CASE("Range overflow for random integer numbers")
{
    bool isRangeOverflow = false;

    // From lower to greater
    for (std::uint8_t i{0u};
         i < std::numeric_limits<std::uint8_t>::max() && !isRangeOverflow;
         ++i)
    {
        const auto randomNumber = Random DOT get(-1, 1);
        isRangeOverflow = randomNumber < -1 || randomNumber > 1;
    }
    REQUIRE(!isRangeOverflow);

    // From greater to lower
    for (std::uint8_t i{0u};
         i < std::numeric_limits<std::uint8_t>::max();
         ++i)
    {
        const auto randomNumber = Random DOT get(1, -1);
        isRangeOverflow = randomNumber < -1 || randomNumber > 1;
    }
    REQUIRE(!isRangeOverflow);

    // Range with 0 gap
    for (std::uint8_t i{0u};
         i < std::numeric_limits<std::uint8_t>::max();
         ++i)
    {
        const auto randomNumber = Random DOT get(0, 0);
        isRangeOverflow = randomNumber != 0;
    }
    REQUIRE(!isRangeOverflow);
}
