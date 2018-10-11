

SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
EXEC = raytracer

CC = g++

CFLAGS = -g
LDFLAGS = -Llib -lgtest -lgtest_main -lpthread
IFLAGS = -Iinclude

all : $(EXEC)

%.o : %.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS)

$(EXEC) : $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(IFLAGS)

clean:
	rm -f $(EXEC) *~ ./src/*.o
