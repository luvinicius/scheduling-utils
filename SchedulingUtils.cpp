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


// Time Functions
int compareHours(int hour1, int minute1, int second1, int hour2, int minute2, int second2)
{
  int dif = (hour1 * 60 * 60 + minute1 * 60 + second1) - (hour2 * 60 * 60 + minute2 * 60 + second2);
  return dif > 0 ? 1 : dif < 0 ? -1
                               : 0;
}
