#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include <TimeLib.h>
#include <SchedulingUtils.h>
#include <SchedulingUtils.cpp>

TEST_SUITE("Date comparision Tests")
{
    TEST_CASE("Compare equal dates")
    {
        CHECK(compareDates(/*first*/ 0, 2022, 12, 1,
                           /*second*/ 0, 2022, 12, 1) == 0);
        CHECK(compareDates(/*first*/ 0, 2022, 5, 10,
                           /*second*/ 0, 2022, 5, 10) == 0);
        CHECK(compareDates(/*first*/ 0, 0, 1, 1,
                           /*second*/ 0, 0, 1, 1) == 0);
        CHECK(compareDates(/*first*/ 0, 0, 6, 6,
                           /*second*/ 0, 0, 6, 6) == 0);
        CHECK(compareDates(/*first*/ 1, 0, 0, 0,
                           /*second*/ 1, 0, 0, 0) == 0);
    }

    TEST_CASE("Compare after dates")
    {
        CHECK(compareDates(/*first*/ 0, 2023, 12, 1,
                           /*second*/ 0, 2022, 12, 1) == 1);
        CHECK(compareDates(/*first*/ 0, 0, 12, 1,
                           /*second*/ 0, 0, 9, 1) == 1);
        CHECK(compareDates(/*first*/ 0, 0, 12, 3,
                           /*second*/ 0, 0, 12, 1) == 1);
        CHECK(compareDates(/*first*/ 2, 0, 0, 0,
                           /*second*/ 1, 0, 0, 0) == 1);
    }

    TEST_CASE("Compare before dates")
    {
        CHECK(compareDates(/*first*/ 0, 2022, 12, 1,
                           /*second*/ 0, 2023, 12, 1) == -1);
        CHECK(compareDates(/*first*/ 0, 0, 1, 1,
                           /*second*/ 0, 0, 2, 1) == -1);
        CHECK(compareDates(/*first*/ 0, 0, 1, 1,
                           /*second*/ 0, 0, 1, 2) == -1);
        CHECK(compareDates(/*first*/ 1, 0, 0, 0,
                           /*second*/ 6, 0, 0, 0) == -1);
    }
}

TEST_SUITE("Hour comparision Tests")
{
    TEST_CASE("Compare equal hours")
    {
        CHECK(compareHours(/*first*/ 0, 0, 0,
                           /*second*/ 0, 0, 0) == 0);
        CHECK(compareHours(/*first*/ 12, 30, 0,
                           /*second*/ 12, 30, 0) == 0);
        CHECK(compareHours(/*first*/ 23, 59, 59,
                           /*second*/ 23, 59, 59) == 0);
    }

    TEST_CASE("Compare after hours")
    {
        CHECK(compareHours(/*first*/ 10, 0, 0,
                           /*second*/ 0, 0, 0) == 1);
        CHECK(compareHours(/*first*/ 0, 30, 0,
                           /*second*/ 0, 15, 0) == 1);
        CHECK(compareHours(/*first*/ 12, 20, 10,
                           /*second*/ 12, 20, 0) == 1);
        CHECK(compareHours(/*first*/ 23, 59, 59,
                           /*second*/ 0, 0, 0) == 1);
    }

    TEST_CASE("Compare before hours")
    {
        CHECK(compareHours(/*first*/ 8, 0, 0,
                           /*second*/ 12, 0, 0) == -1);
        CHECK(compareHours(/*first*/ 12, 30, 0,
                           /*second*/ 12, 45, 0) == -1);
        CHECK(compareHours(/*first*/ 18, 20, 0,
                           /*second*/ 18, 20, 40) == -1);
        CHECK(compareHours(/*first*/ 0, 0, 0,
                           /*second*/ 23, 59, 59) == -1);
    }
}
