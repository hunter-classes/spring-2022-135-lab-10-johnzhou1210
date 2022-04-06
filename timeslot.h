#pragma once
#include "movie.h"
#include "time.h"

class TimeSlot {
public:
  Movie movie; // what Movie
  Time startTime; // when it starts
};

std::string getTimeSlot(TimeSlot ts);

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

bool timeOverlap(TimeSlot t1, TimeSlot t2);
