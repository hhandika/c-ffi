CXX = g++
CXXFLAGS= -Wall -Werror -Wextra -pedantic -o3 -std=c++11
CC = gcc
CFLAGS=	-Wall -Werror -Wextra -pedantic -o3 -lm -std=c11
TARGET= cpp_ffi
OBJS= main.o vector.o
DEPS= vector.h

%.o: %.cpp $(DEPS)
	$(CXX) -c $< $(CXXFLAGS) -o $@

# Compile the C code into an object files separately
%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

exe: $(OBJS)
	$(CXX) $^ $(CXXFLAGS) -o $(TARGET)

clean:
	rm *.o

cleanall:
	rm *.o $(TARGET)