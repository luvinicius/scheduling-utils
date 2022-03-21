/*
  Scheduling Utils
  AUTOR:        Lucas Vinicius Pimenta
  LINKS:        https://github.com/luvinicius/scheduling-utils
  DESCRIPTION:  Scheduling types and functions
*/

#ifndef _Scheduling_Utils
#ifdef __cplusplus
#define _Scheduling_Utils

#include <TimeLib.h>

extern "C++"
{


  /*============================================================================*/
  /* Date functions */
  int compareDates(int wDay1, int year1, int month1, int day1, int wDay2, int year2, int month2, int day2);
  

  // Time Functions
  int compareHours(int hour1, int minute1, int second1, int hour2, int minute2, int second2);
  

} /* extern "C++"*/
#endif /* __cplusplus*/
#endif /* _Scheduling_Utils */
