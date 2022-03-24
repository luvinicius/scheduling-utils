/*
  Scheduling Utils
  AUTOR:        Lucas Vinicius Pimenta
  LINKS:        https://github.com/luvinicius/scheduling-utils
  DESCRIPTION:  Scheduling functions
*/

#include <math.h>
#include "SchedulingUtils.h"
#include <TimeLib.h>

/*============================================================================*/
/* Date functions */

int compareDates(int wDay1, int year1, int month1, int day1, int wDay2, int year2, int month2, int day2)
{
  if (year1 != 0 && year2 != 0)
  {
    if (year1 > year2)
    {
      return 1;
    }
    else if (year1 < year2)
    {
      return -1;
    }
  }
  if (month1 != 0 && month2 != 0)
  {
    if (month1 > month2)
    {
      return 1;
    }
    else if (month1 < month2)
    {
      return -1;
    }

    if (day1 != 0 && day2 != 0)
    {
      if (day1 > day2)
      {
        return 1;
      }
      else if (day1 < day2)
      {
        return -1;
      }
    }
  }

  if (wDay1 != 0 && wDay2 != 0)
  {
    if (wDay1 > wDay2)
    {
      return 1;
    }
    else if (wDay1 < wDay2)
    {
      return -1;
    }
  }

  return 0;
}

int compareDates(tmElements_t tm1, tmElements_t tm2)
{
  return compareDates(tm1.Wday,
                      tm1.Year,
                      tm1.Month,
                      tm1.Day,
                      tm2.Wday,
                      tm2.Year,
                      tm2.Month,
                      tm2.Day);
}

bool isSameDay(tmElements_t tm1, tmElements_t tm2)
{
  return tm1.Year == tm2.Year && tm1.Month == tm2.Month && tm1.Day == tm2.Day && tm1.Wday == tm2.Wday;
}

bool isAfterOrSameDay(tmElements_t tm1, tmElements_t tm2)
{
  return isSameDay(tm1, tm2) || compareDates(tm1, tm2) > 0;
}
bool isBeforeOrSameDay(tmElements_t tm1, tmElements_t tm2)
{
  return isSameDay(tm1, tm2) || compareDates(tm1, tm2) < 0;
}

// Time Functions

int compareHours(int hour1, int minute1, int second1, int hour2, int minute2, int second2)
{
  int dif = (hour1 * 60 * 60 + minute1 * 60 + second1) - (hour2 * 60 * 60 + minute2 * 60 + second2);
  return dif > 0 ? 1 : dif < 0 ? -1
                               : 0;
}

int compareHours(tmElements_t Time1, tmElements_t Time2)
{
  return compareHours(Time1.Hour, Time1.Minute, Time1.Second, Time2.Hour, Time2.Minute, Time2.Second);
}

bool isAfterOrSameHour(tmElements_t Time1, tmElements_t Time2)
{
  return compareHours(Time1, Time2) >= 0;
}
bool isBeforeOrSameHour(tmElements_t Time1, tmElements_t Time2)
{
  return compareHours(Time1, Time2) <= 0;
}

int getNumberOfDigitsInTheYear(int year)
{
  int numberOfDigits = 1;
  int subtractor = 10;
  while (year - subtractor >= 0)
  {
    numberOfDigits = numberOfDigits + 1;
    subtractor = subtractor * 10;
  }

  return numberOfDigits;
}

int *getDigitsOfYear(int year)
{
  int numberOfDigits = getNumberOfDigitsInTheYear(year);
  int divisor = (int)floor(pow(10, (numberOfDigits - 1)));

  int *digits = new int[numberOfDigits];
  for (int i = 0; i < numberOfDigits; i++)
  {
    digits[i] = (int)floor(year / divisor);
    year -= digits[i] * divisor;
    divisor /= 10;
  }

  return digits;
}

bool isLeapYear(int year)
{
  int *digits = getDigitsOfYear(year);
  int numerOfDigits = sizeof(digits) / sizeof(digits[0]);
  int index = numerOfDigits - 1;
  int decimal = digits[index];
  index--;
  int multiplier = 10;
  decimal += digits[index] * multiplier;

  int divider = 4;
  while (decimal == 0 && index >= 0)
  {
    index--;
    multiplier *= 10;
    divider *= multiplier;
    decimal += digits[index] * multiplier;
  }
  delete[] digits;
  return decimal != 0 && decimal % divider == 0;
}

int numberOfDays(int year, int month)
{
  return 0;
}

tmElements_t sumToDate(tmElements_t tm, int Units, Duration Measure)
{
  tmElements_t finalTm = tmElements_t();
  finalTm.Hour = tm.Hour;
  finalTm.Minute = tm.Minute;
  finalTm.Second = tm.Second;
  finalTm.Day = tm.Day;
  finalTm.Wday = tm.Wday;
  finalTm.Month = tm.Month;
  finalTm.Year = tm.Year;

  switch (Measure)
  {
  case SECONDS:
    finalTm.Second += Units;
    break;
  case MINUTES:
    finalTm.Minute += Units;
    break;
  case HOURS:
    finalTm.Hour += Units;
    break;
  case DAYS:
    finalTm.Day += Units;
    finalTm.Wday += Units;
    break;
  case MONTHS:
    finalTm.Month += Units;
    break;
  case YEARS:
    finalTm.Year += Units;
    break;
  }

  if (finalTm.Second > 60)
  {
    finalTm.Minute += round(finalTm.Second / 60);
    finalTm.Second -= 60;
  }

  if (finalTm.Minute > 60)
  {
    finalTm.Hour += round(finalTm.Minute / 60);
    finalTm.Minute -= 60;
  }

  if (finalTm.Hour > 23)
  {
    if (finalTm.Day < 31)
    {
      finalTm.Day += round(finalTm.Hour / 24);
    }
    finalTm.Hour -= 24;
  }

  return finalTm;
}