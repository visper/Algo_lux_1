CC=g++
FLAGS=-std=c++11 -O2 -Wall
TGT=nativeSearch

all:
	$(CC) $(FLAGS) \
	nativeSearch.cpp  test.cpp  main.cpp \
	-o $(TGT)

clean:
	rm -rf $(TGT)
	rm -rf *.o
