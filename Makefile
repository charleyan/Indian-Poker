CC=g++ -g -Wall -std=c++14

# List of source files for Indian Poker
IP_SOURCES=main.cpp game.cpp card.cpp player.cpp deck.cpp

# Generate the names of the file server's object files
IP_OBJS=${IP_SOURCES:.cpp=.o}

all: ip 

# Compile the Indian Poker program
ip: ${IP_OBJS}
	${CC} -o $@ $^

# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cpp
	${CC} -c $<

clean:
	rm -rf ${IP_OBJS} ip
