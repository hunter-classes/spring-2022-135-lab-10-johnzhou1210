#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"
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
  returnVal = addMinutes({4,44}, 1450); cout << "addMinutes({4,44}, 1450) returns: " << "{" << returnVal.h << ", " << returnVal.m << "}" << "\n\n";
  cout << "============== TASK C ===============\n";
  cout << "getTimeSlot({ {\"Spoodermane Adevntures\",THRILLER,116} , {9,15} }) returns:\n" << getTimeSlot({ {"Spoodermane Adevntures",THRILLER,116} , {9,15} }) << "\n\n";
  cout << "getTimeSlot({ {\"Noir Big Cat\",ACTION,152} , {12,30} }) returns:\n" << getTimeSlot({ {"Noir Big Cat",ACTION,152} , {12,30} }) << "\n\n";
  cout << "getTimeSlot({ {\"Cliche Tear-jerker\",DRAMA,183} , {18,45} }) returns:\n" << getTimeSlot({ {"Cliche Tear-jerker",DRAMA,183} , {18,45} }) << "\n\n";
  cout << "getTimeSlot({ {\"Sappy Love Story\",ROMANCE,136} , {20,00} }) returns:\n" << getTimeSlot({ {"Sappy Love Story",ROMANCE,136} , {20,00} }) << "\n\n";
  cout << "getTimeSlot({ {\"Self-proclaimed World-class Comedian\",COMEDY,95} , {6,15} }) returns:\n" << getTimeSlot({ {"Self-proclaimed World-class Comedian",COMEDY,95} , {6,15} }) << "\n\n";
  cout << "============== TASK D ===============\n";
  TimeSlot newTimeSlot = scheduleAfter( {{"Spoodermane Adventures",THRILLER,116},{9,15}}, {"Noir Big Cat",ACTION,152} );
  cout << "scheduleAfter( {{\"Spoodermane Adventures\",THRILLER,116},{9,15}}, {\"Noir Big Cat\",ACTION,152} )\ncontains the following time slot after displaying:\n" << getTimeSlot(newTimeSlot) << "\n\n";
  newTimeSlot = scheduleAfter( {{"Noir Big Cat",ACTION,152},{11,11}}, {"Sappy Love Story",ROMANCE,136} );
  cout << "scheduleAfter( {{\"Noir Big Cat\",ACTION,152},{11,11}}, {\"Sappy Love Story\",ROMANCE,136} )\ncontains the following time slot after displaying:\n" << getTimeSlot(newTimeSlot) << "\n\n";
  newTimeSlot = scheduleAfter( {{"Self-proclaimed World-class Comedian",COMEDY,95},{6,15}}, {"Cliche Tear-jerker",DRAMA,183} );
  cout << "scheduleAfter( {{\"Self-proclaimed World-class Comedian\",COMEDY,95},{6,15}}, {\"Cliche Tear-jerker\",DRAMA,183} )\ncontains the following time slot after displaying:\n" << getTimeSlot(newTimeSlot) << "\n\n";
  cout << "============== TASK E ===============\n";
  TimeSlot ts1 = { {"Spoodermane Adventures",THRILLER,116}, {9,15} }, ts2 = { {"Noir Big Cat",ACTION,152}, {11,11} };
  cout << "timeOverlap function with\nts1 after displaying: " << getTimeSlot(ts1) <<"\nts2 after displaying: " << getTimeSlot(ts2) << "\nreturns: " << std::boolalpha << timeOverlap(ts1,ts2) << "\n\n";
  ts1 = { {"Noir Big Cat",ACTION,152}, {11,11} }; ts2 = { {"Sappy Love Story",ROMANCE,152}, {13,40} };
  cout << "timeOverlap function with\nts1 after displaying: " << getTimeSlot(ts1) <<"\nts2 after displaying: " << getTimeSlot(ts2) << "\nreturns: " << std::boolalpha << timeOverlap(ts1,ts2) << "\n\n";
  ts1 = { {"Self-proclaimed World-class Comedian",COMEDY,95}, {6,15} }; ts2 = { {"Cliche Tear-jerker",DRAMA,183}, {4,45} };
  cout << "timeOverlap function with\nts1 after displaying: " << getTimeSlot(ts1) <<"\nts2 after displaying: " << getTimeSlot(ts2) << "\nreturns: " << std::boolalpha << timeOverlap(ts1,ts2) << "\n\n";
  cout << "============= END OF TASKS ============\n";
  return 0;
}
