testcards: testcards.o cards.o
	g++ testcards.o cards.o -o testcards

game: main.o cards.o
	g++ main.o cards.o -o game

main.o: main.cpp
	g++ main.cpp -c

cards.o: cards.cpp
	g++ cards.cpp -c

testcards.o: testcards.cpp
	g++ testcards.cpp -c

clean:
	rm *.o *.txt a.out testcards game 
