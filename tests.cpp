#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"
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

TEST_CASE("TASK C: getTimeSlot function") {
  CHECK(getTimeSlot({ {"Spoodermane Adevntures",THRILLER,116} , {9,15} }) == "Spoodermane Adevntures THRILLER (116 min) [starts at 9:15, ends by 11:11]");
  CHECK(getTimeSlot({ {"Noir Big Cat",ACTION,152} , {12,30} }) == "Noir Big Cat ACTION (152 min) [starts at 12:30, ends by 15:2]");
  CHECK(getTimeSlot({ {"Cliche Tear-jerker",DRAMA,183} , {18,45} }) == "Cliche Tear-jerker DRAMA (183 min) [starts at 18:45, ends by 21:48]");
  CHECK(getTimeSlot({ {"Sappy Love Story",ROMANCE,136} , {20,00} }) == "Sappy Love Story ROMANCE (136 min) [starts at 20:0, ends by 22:16]");
  CHECK(getTimeSlot({ {"Self-proclaimed World-class Comedian",COMEDY,95} , {6,15} }) == "Self-proclaimed World-class Comedian COMEDY (95 min) [starts at 6:15, ends by 7:50]");
}

TEST_CASE("TASK D: scheduleAfter function") {
  TimeSlot newTimeSlot = scheduleAfter( {{"Spoodermane Adventures",THRILLER,116},{9,15}}, {"Noir Big Cat",ACTION,152} );
  CHECK(getTimeSlot(newTimeSlot) == "Noir Big Cat ACTION (152 min) [starts at 11:11, ends by 13:43]");
  newTimeSlot = scheduleAfter( {{"Noir Big Cat",ACTION,152},{11,11}}, {"Sappy Love Story",ROMANCE,136} );
  CHECK(getTimeSlot(newTimeSlot) == "Sappy Love Story ROMANCE (136 min) [starts at 13:43, ends by 15:59]");
  newTimeSlot = scheduleAfter( {{"Self-proclaimed World-class Comedian",COMEDY,95},{6,15}}, {"Cliche Tear-jerker",DRAMA,183} );
  CHECK(getTimeSlot(newTimeSlot) == "Cliche Tear-jerker DRAMA (183 min) [starts at 7:50, ends by 10:53]");
}

TEST_CASE("TASK E: timeOverlap function") {
  TimeSlot ts1 = { {"Spoodermane Adventures",THRILLER,116}, {9,15} }, ts2 = { {"Noir Big Cat",ACTION,152}, {11,11} };
  CHECK(timeOverlap(ts1,ts2) == false);
  ts1 = { {"Noir Big Cat",ACTION,152}, {11,11} }; ts2 = { {"Sappy Love Story",ROMANCE,152}, {13,40} };
  CHECK(timeOverlap(ts1,ts2) == true);
  ts1 = { {"Self-proclaimed World-class Comedian",COMEDY,95}, {6,15} }; ts2 = { {"Cliche Tear-jerker",DRAMA,183}, {4,45} };
  CHECK(timeOverlap(ts1,ts2) == true);
}
