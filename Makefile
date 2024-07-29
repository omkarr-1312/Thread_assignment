# Define the compiler
CC = cc

# Define the flags for the compiler
CFLAGS = -Wall -pthread

# Define the source files
SRCS = main.c sort_file.c merge_file.c

# Define the header files
HDRS = sort_file.h merge_file.h

# Define the object files
OBJS = main.o sort_file.o merge_file.o

# Define the name of the executable
EXEC = thread.exe

# The default rule
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Rule to build the main.o file
main.o: main.c $(HDRS)
	$(CC) $(CFLAGS) -c main.c

# Rule to build the sort_file.o file
sort_file.o: sort_file.c sort_file.h
	$(CC) $(CFLAGS) -c sort_file.c

# Rule to build the merge_file.o file
merge_file.o: merge_file.c merge_file.h
	$(CC) $(CFLAGS) -c merge_file.c

# Rule to clean up the directory
clean:
	rm -f $(OBJS) $(EXEC) sorted*

