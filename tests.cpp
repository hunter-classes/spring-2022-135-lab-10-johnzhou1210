#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include <iostream>

TEST_CASE("TASK A: minutesSinceMidnight and minutesUntil functions") {
  CHECK(minutesSinceMidnight({10,30}) == 630);
  CHECK(minutesSinceMidnight({13,40}) == 820);
  CHECK(minutesUntil({10,30}, {13,40}) == 190);

  CHECK(minutesSinceMidnight({15,42}) == 942);
  CHECK(minutesSinceMidnight({2,11}) == 131);
  CHECK(minutesUntil({15,42}, {2,11}) == -811);

  CHECK(minutesSinceMidnight({11,59}) == 719);
  CHECK(minutesSinceMidnight({11,59}) == 719);
  CHECK(minutesUntil({11,59}, {11,59}) == 0);

  CHECK(minutesSinceMidnight({0,0}) == 0);
  CHECK(minutesSinceMidnight({23,59}) == 1439);
  CHECK(minutesUntil({0,0}, {23,59}) == 1439);
}

TEST_CASE("TASK B: addMinutes function") {
  Time returnVal = addMinutes({8,10}, 75);
  bool comparison = (returnVal.h == 9 && returnVal.m == 25);
  CHECK(comparison);
  returnVal = addMinutes({0,0}, 1440); comparison = (returnVal.h == 0 && returnVal.m == 0); CHECK(comparison);
  returnVal = addMinutes({16,20}, -360); comparison = (returnVal.h == 10 && returnVal.m == 20); CHECK(comparison);
  returnVal = addMinutes({0,11}, -13); comparison = (returnVal.h == 23 && returnVal.m == 58); CHECK(comparison);
  returnVal = addMinutes({4,44}, 1450); comparison = (returnVal.h == 4 && returnVal.m == 54); CHECK(comparison);
}
