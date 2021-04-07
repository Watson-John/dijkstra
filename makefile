## John Watson
## CS 365 
## Project 1
## 4/11/2021


EX: driver.o path.o
	g++ -o EX driver.o path.o
path.o: path.cpp path.h
	g++ -c path.cpp
clean:
	rm *.o
