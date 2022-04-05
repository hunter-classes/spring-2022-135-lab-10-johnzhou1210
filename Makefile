main: main.o time.o
	g++ -o main main.o time.o

tests: tests.o time.o
	g++ -o tests tests.o time.o

main.o: main.cpp time.h time.o

time.o: time.cpp time.h

clean:
	rm -f main.o tests.o time.o
