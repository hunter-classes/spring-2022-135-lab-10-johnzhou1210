#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string timeStr(Time t) {
  // std::cout << t.h << ":" << t.m << "\n";
  return std::to_string(t.h) + ":" + std::to_string(t.m);
}

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

std::string movieStr(Movie mv) {
  std::string g;
  switch (mv.genre) {
      case ACTION   : g = "ACTION"; break;
      case COMEDY   : g = "COMEDY"; break;
      case DRAMA    : g = "DRAMA";  break;
      case ROMANCE  : g = "ROMANCE"; break;
      case THRILLER : g = "THRILLER"; break;
  }
  return mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
}

std::string getTimeSlot(TimeSlot ts) {
  Time endTime = addMinutes(ts.startTime, ts.movie.duration);
  // std::cout << timeStr(endTime) << "\n";
  return movieStr(ts.movie) + " [starts at " + timeStr(ts.startTime) + ", ends by " + timeStr(endTime) + "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
  Time endTime = addMinutes(ts.startTime, ts.movie.duration);
  return {nextMovie, endTime};
}

bool timeOverlap(TimeSlot t1, TimeSlot t2) {
  int t1Start = minutesSinceMidnight(t1.startTime), t2Start = minutesSinceMidnight(t2.startTime);
  int t1End = t1Start + t1.movie.duration, t2End = t2Start + t2.movie.duration;
  /*
  cases to consider:
  t1Start = 10; t1End = 60;
  t2Start = 20; t2End = 80;

  t2Start = 10; t2End = 60;
  t1Start = 20; t1End = 80;

  t1Start = 10; t1End = 60;
  t2Start = 60; t2End = 130;

  t2Start = 10; t2End = 60;
  t1Start = 60; t1End = 130;
  */
  bool noOverlap = (t1Start < t2Start && t1End <= t2Start) || (t2Start < t1Start && t2End <= t1Start);
  if (noOverlap) {
    return false;
  }
  return true;
}
