CC=g++
#FLAGS=-std=c++11 -O2 -Wall -g
FLAGS=-std=c++11 -Wall -g
#FLAGS= -g -o
TGT=nativeSearch

all:
	$(CC) $(FLAGS) \
	nativeSearch.cpp  test.cpp  main.cpp \
	-o $(TGT)

clean:
	rm -rf $(TGT)  2>/dev/null
	rm -rf *.o     2>/dev/null
