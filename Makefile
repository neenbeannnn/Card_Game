movies: main.o movies.o
	g++ main.o movies.o -o movies
#utility.o
tests: tests.o movies.o
	g++ tests.o movies.o -o tests
	./tests
movies.o: movies.cpp
	g++ movies.cpp -c
tests.o: tests.cpp
	g++ tests.cpp -c
#utility.o: utility.cpp
	#g++ utility.cpp -c
main.o: main.cpp
	g++ main.cpp -c
clean:
	rm *.o movies tests
