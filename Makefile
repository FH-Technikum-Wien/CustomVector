CC = clang++
LFLAGS = -std=c++17 -g -Wall -pedantic -Weffc++ -Wextra -Wfatal-errors -Werror

all: main.cpp vector.h
	${CC} ${LFLAGS} main.cpp -o main
	
clean:
	rm -f main