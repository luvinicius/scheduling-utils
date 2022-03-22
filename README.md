# Scheduling Utils
Provides simple structures and functions to create and use scheduling information.

# Main functions
## compareDates
Compare the first date with the second and returns the relation between the two dates.
## compateHours
Compare the first hour with the second and returns the relation between the two hours.

## Testing:
Tests are written using Doctest library.

To execute tests must run the SchedulingUtilsTest.cpp
Will need to pass throw the doctest libary path or has it add to system general c++ libary folder.
Will need to pass  throw Timelib path too.

Exemple how to run in linux:
```
cd tests/
g++ SchedulingUtilsTest.cpp -I <PATH_TO_DOCTESTS LIBARY> -I <PATH_TO_TIMELIB> -I ../ && clear && ./a.out
```

## Dependencies:
[Arduino Time Library by PaulStoffregen](https://github.com/PaulStoffregen/Time).

[Doctest](https://github.com/doctest/doctest) is used to unit tests. You can download the latest version [here](https://raw.githubusercontent.com/onqtam/doctest/master/doctest/doctest.h).
