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
  /**
   * @brief Compare the first date with the second and returns the relation between the two dates
   *
   * @param wDay1 first date day of week, sunday is day 1, pass 0 to ignore
   * @param year1 first date year, pass 0 to ignore
   * @param month1 first date month, pass 0 to ignore
   * @param day1 first date day, pass 0 to ignore
   * @param wDay2 second date day of week, sunday is day 1, pass 0 to ignore
   * @param year2 second date year, pass 0 to ignore
   * @param month2 second date month, pass 0 to ignore
   * @param day2  second date day, pass 0 to ignore
   * @warning Will return 0 if it's not possible compare dates, use isSameDay for more precision.
   * @return int : 1 the first date is after the second date;
                  -1 the fist date is before the second date;
                  Or 0 the first date is equal to the second date.
   */
  int compareDates(int wDay1, int year1, int month1, int day1, int wDay2, int year2, int month2, int day2);

  /**
   * @brief Compare the first date with the second and returns the relation between the two dates
   *
   * @param Date1 first date
   * @param Date2 second date
   * @warning Will return 0 if it's not possible compare dates, use isSameDay for more precision.
   * @return int : 1 the first date is after the second date;
                  -1 the fist date is before the second date;
                  Or 0 the first date is equal to the second date.
   */
  int compareDates(tmElements_t Date1, tmElements_t Date2);

  bool isSameDay(tmElements_t tm1, tmElements_t tm2);
  bool isAfterOrSameDay(tmElements_t tm1, tmElements_t tm2);
  bool isBeforeOrSameDay(tmElements_t tm1, tmElements_t tm2);

  // Time Functions
  /**
   * @brief Compare the first hour with the second and returns the relation between the two hours
   *
   * @param hour1 first hour
   * @param minute1 first minute
   * @param second1 first second
   * @param hour2 second hour
   * @param minute2 second minute
   * @param second2  second second
   * @return int : 1 the first hour is after the hour date;
                  -1 the fist hour is before the hour date;
                  Or 0 the first hour is equal to the hour date.
   */
  int compareHours(int hour1, int minute1, int second1, int hour2, int minute2, int second2);

  /**
   * @brief Compare the first hour with the second and returns the relation between the two hours
   *
   * @param Time1 first hour
   * @param Time2 second hour
   * @return int : 1 the first hour is after the hour date;
                  -1 the fist hour is before the hour date;
                  Or 0 the first hour is equal to the hour date.
   */
  int compareHours(tmElements_t Time1, tmElements_t Time2);

  bool isAfterOrSameHour(tmElements_t Time1, tmElements_t Time2);
  bool isBeforeOrSameHour(tmElements_t Time1, tmElements_t Time2);

  int getNumberOfDigitsInTheYear(int year);

  int * getDigitsOfYear(int year);

  

} /* extern "C++"*/
#endif /* __cplusplus*/
#endif /* _Scheduling_Utils */
