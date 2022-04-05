#include <iostream>
#include "time.h"

int minutesSinceMidnight(Time time) {
  return (time.h * 60) + time.m;
}

int minutesUntil(Time earlier, Time later) {
  int earlierPos = minutesSinceMidnight(earlier), laterPos = minutesSinceMidnight(later);
  return laterPos - earlierPos; // don't take absolute value; if earlierPos comes later, just return negative integer.
}

Time addMinutes(Time time0, int min) {
  // minutes with abosolute value greater than 1440 will be adjust to a number on [-1440,1440]
  // there are (60 * 24) = 1440 minutes in a day
  while ((abs(min) > (1440))) {
    if (min > 0) {
      min = min - 1440;
    } else {
      min = min + 1440;
    }
  }
  // now minutes should be on [-1440,1440]
  // convert time0 with the added minutes to minutes after midnight
  int minAftMid = minutesSinceMidnight(time0) + min;
  // edge case: if minAftMid is negative (min was negative), then set minAftMid = (1440) + minAftMid
  if (minAftMid < 0) {
    minAftMid = (1440) + minAftMid;
  }
  // convert minAftMid into a Time object with the right hours and minutes
  int newHrs = minAftMid / 60; int newMins = minAftMid % 60;
  if (newHrs == 24) { newHrs = 0; } 
  Time result = {newHrs, newMins};
  return result;
}
