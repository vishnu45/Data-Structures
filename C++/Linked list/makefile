OBJS = testDriver.o LinkedList.o
CC = g++
DEBUG = -g -w
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

testDriver: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o Test

testDriver.o: \
	LinkedList.h LinkedList.cpp \
 	testDriver.cpp
	$(CC) $(CFLAGS) testDriver.cpp

LinkedList.o: \
	LinkedList.h LinkedList.cpp
	$(CC) $(CFLAGS) LinkedList.cpp

clean:
	del $(OBJS) Test.exe