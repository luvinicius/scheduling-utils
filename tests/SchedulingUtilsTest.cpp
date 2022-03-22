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

    TEST_CASE("Compare equal dates with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Year = 2022;
        tm1.Month = 8;
        tm1.Day = 28;
        tmElements_t tm2 = tmElements_t();
        tm2.Year = 2022;
        tm2.Month = 8;
        tm2.Day = 28;
        CHECK(compareDates(tm1, tm2) == 0);
        CHECK(isSameDay(tm1, tm2));
        CHECK(isAfterOrSameDay(tm1, tm2));
        CHECK(isBeforeOrSameDay(tm1, tm2));

        tmElements_t tm3 = tmElements_t();
        tm3.Month = 6;
        tm3.Day = 7;
        tmElements_t tm4 = tmElements_t();
        tm4.Month = 6;
        tm4.Day = 7;
        CHECK(compareDates(tm3, tm4) == 0);
        CHECK(isSameDay(tm3, tm4));
        CHECK(isAfterOrSameDay(tm3, tm4));
        CHECK(isBeforeOrSameDay(tm3, tm4));

        tmElements_t tm5 = tmElements_t();
        tm5.Wday = 2;
        tmElements_t tm6 = tmElements_t();
        tm6.Wday = 2;
        CHECK(compareDates(tm5, tm6) == 0);
        CHECK(isSameDay(tm5, tm6));
        CHECK(isAfterOrSameDay(tm5, tm6));
        CHECK(isBeforeOrSameDay(tm5, tm6));

        CHECK(!isSameDay(tm1, tm3));
        CHECK(!isSameDay(tm2, tm4));
        CHECK(!isSameDay(tm1, tm5));
        CHECK(!isSameDay(tm3, tm6));
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

    TEST_CASE("Compare after dates with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Year = 1991;
        tm1.Month = 6;
        tm1.Day = 7;
        tmElements_t tm2 = tmElements_t();
        tm2.Year = 1990;
        tm2.Month = 6;
        tm2.Day = 7;
        CHECK(compareDates(tm1, tm2) == 1);
        CHECK(isAfterOrSameDay(tm1, tm2));
        CHECK(!isBeforeOrSameDay(tm1, tm2));

        tmElements_t tm3 = tmElements_t();
        tm3.Month = 8;
        tm3.Day = 28;
        tmElements_t tm4 = tmElements_t();
        tm4.Month = 6;
        tm4.Day = 7;
        CHECK(compareDates(tm3, tm4) == 1);
        CHECK(isAfterOrSameDay(tm3, tm4));
        CHECK(!isBeforeOrSameDay(tm3, tm4));

        tmElements_t tm5 = tmElements_t();
        tm5.Wday = 4;
        tmElements_t tm6 = tmElements_t();
        tm6.Wday = 2;
        CHECK(compareDates(tm5, tm6) == 1);
        CHECK(isAfterOrSameDay(tm5, tm6));
        CHECK(!isBeforeOrSameDay(tm5, tm6));
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

    TEST_CASE("Compare before dates with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Year = 2015;
        tm1.Month = 1;
        tm1.Day = 1;
        tmElements_t tm2 = tmElements_t();
        tm2.Year = 2018;
        tm2.Month = 1;
        tm2.Day = 1;
        CHECK(compareDates(tm1, tm2) == -1);
        CHECK(isBeforeOrSameDay(tm1, tm2));
        CHECK(!isAfterOrSameDay(tm1, tm2));

        tmElements_t tm3 = tmElements_t();
        tm3.Month = 4;
        tm3.Day = 1;
        tmElements_t tm4 = tmElements_t();
        tm4.Month = 12;
        tm4.Day = 23;
        CHECK(compareDates(tm3, tm4) == -1);
        CHECK(isBeforeOrSameDay(tm3, tm4));
        CHECK(!isAfterOrSameDay(tm3, tm4));

        tmElements_t tm5 = tmElements_t();
        tm5.Wday = 5;
        tmElements_t tm6 = tmElements_t();
        tm6.Wday = 6;
        CHECK(compareDates(tm5, tm6) == -1);
        CHECK(isBeforeOrSameDay(tm5, tm6));
        CHECK(!isAfterOrSameDay(tm5, tm6));
    }
}

TEST_SUITE("Time comparision Tests")
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

    TEST_CASE("Compare equal hours with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Hour = 10;
        tm1.Minute = 43;
        tm1.Second = 27;
        tmElements_t tm2 = tmElements_t();
        tm2.Hour = 10;
        tm2.Minute = 43;
        tm2.Second = 27;
        CHECK(compareHours(tm1, tm2) == 0);
        CHECK(isAfterOrSameHour(tm1, tm2));
        CHECK(isBeforeOrSameHour(tm1, tm2));

        tmElements_t tm4 = tmElements_t();
        tm4.Minute = 49;
        tm4.Second = 59;
        tmElements_t tm5 = tmElements_t();
        tm5.Minute = 49;
        tm5.Second = 59;

        CHECK(compareHours(tm4, tm5) == 0);
        CHECK(isAfterOrSameHour(tm4, tm5));
        CHECK(isBeforeOrSameHour(tm4, tm5));
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

    TEST_CASE("Compare after hours with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Hour = 12;
        tm1.Minute = 30;
        tm1.Second = 1;
        tmElements_t tm2 = tmElements_t();
        tm2.Hour = 12;
        tm2.Minute = 29;
        tm2.Second = 59;
        CHECK(compareHours(tm1, tm2) == 1);
        CHECK(isAfterOrSameHour(tm1, tm2));
        CHECK(!isBeforeOrSameHour(tm1, tm2));
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

    TEST_CASE("Compare before hours with tmElements_t arguments")
    {
        tmElements_t tm1 = tmElements_t();
        tm1.Hour = 13;
        tm1.Minute = 59;
        tm1.Second = 59;
        tmElements_t tm2 = tmElements_t();
        tm2.Hour = 14;
        tm2.Minute = 0;
        tm2.Second = 0;
        CHECK(compareHours(tm1, tm2) == -1);
        CHECK(isBeforeOrSameHour(tm1, tm2));
        CHECK(!isAfterOrSameHour(tm1, tm2));
    }
}
