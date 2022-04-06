main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o

main.o: main.cpp time.h timeslot.h movie.h

time.o: time.cpp time.h timeslot.h movie.h

tests.o: tests.cpp doctest.h time.h timeslot.h movie.h

clean:
	rm -f main.o tests.o time.o
