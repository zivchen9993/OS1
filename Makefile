# Makefile for the smash program
CC = g++
CFLAGS = -g -std=c++11 -Wall 
CCLINK = $(CC)
OBJS = smash.o commands.o signals.o Terminal_class.o Jobs.o SingleJob.o
RM = rm -rf
# Creating the  executable
smash: $(OBJS)
	$(CCLINK) -o smash $(OBJS)
# Creating the object files
smash.o: smash.cpp commands.h Jobs.h Terminal_class.h
	$(CC)  $(CFLAGS) -c smash.cpp
commands.o: commands.cpp commands.h Terminal_class.h Jobs.h
	$(CC)  $(CFLAGS) -c commands.cpp
Jobs.o: Jobs.cpp Jobs.h SingleJob.h
	$(CC)  $(CFLAGS) -c Jobs.cpp
signals.o: signals.cpp signals.h Jobs.h
	$(CC)  $(CFLAGS) -c signals.cpp
Terminal_class.o: Terminal_class.cpp Terminal_class.h
	$(CC)  $(CFLAGS) -c Terminal_class.cpp
SingleJob.o: SingleJob.cpp SingleJob.h
	$(CC)  $(CFLAGS) -c SingleJob.cpp


# Cleaning old files before new make
clean:
	$(RM) $(TARGET) *.o *~ "#"* core.* smash