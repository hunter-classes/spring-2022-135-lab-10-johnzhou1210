#include <iostream>
#include "time.h"
using std::cout;

int main() {
  Time obj = {5,12};
  cout << "============== TASK A ===============\n";
  cout << "minutesSinceMidnight({10,30}) returns: " << minutesSinceMidnight({10,30}) << "\n";
  cout << "minutesSinceMidnight({13,40})  " << minutesSinceMidnight({13,40}) << "\n";
  cout << "minutesUntil({10,30}, {13,40}) returns: " << minutesUntil({10,30}, {13,40}) << "\n\n";

  cout << "minutesSinceMidnight({15,42}) returns: " << minutesSinceMidnight({15,42}) << "\n";
  cout << "minutesSinceMidnight({2,11}) returns: " << minutesSinceMidnight({2,11}) << "\n";
  cout << "minutesUntil({15,42}, {2,11}) returns: " << minutesUntil({15,42}, {2,11}) << "\n\n";

  cout << "minutesSinceMidnight({11,59}) returns: " << minutesSinceMidnight({11,59}) << "\n";
  cout << "minutesSinceMidnight({11,59}) returns: " << minutesSinceMidnight({11,59}) << "\n";
  cout << "minutesUntil({11,59}, {11,59}) returns: " << minutesUntil({11,59}, {11,59}) << "\n\n";

  cout << "minutesSinceMidnight({0,0}) returns: " << minutesSinceMidnight({0,0}) << "\n";
  cout << "minutesSinceMidnight({23,59}) returns: " << minutesSinceMidnight({23,59}) << "\n";
  cout << "minutesUntil({0,0}, {23,59}) returns: " << minutesUntil({0,0}, {23,59}) << "\n\n";
  cout << "============== TASK B ===============\n";
  Time returnVal = addMinutes({8,10}, 75);
  cout << "addMinutes({8,10}, 75) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n";
  returnVal = addMinutes({0,0}, 1440); cout << "addMinutes({0,0}, 1440) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n";
  returnVal = addMinutes({16,20}, -360); cout << "addMinutes({16,20}, -360) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n";
  returnVal = addMinutes({0,11}, -13); cout << "addMinutes({0,11}, -13) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n";
  returnVal = addMinutes({4,44}, 1450); cout << "addMinutes({4,44}, 1450) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n";

  return 0;
}
