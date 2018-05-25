PROJECT = fasm

# Toolchain configurations
CROSS_COMPILE ?=
CC = $(CROSS_COMPILE)g++

SUFFIX ?=
EXECUTABLE = $(PROJECT)$(SUFFIX)

# Basic configurations
CFLAGS += -g -std=c++14
LDFLAGS =

# Optimizations
CFLAGS += -Os

# project starts here
CFLAGS += -I.
OBJS = \
    main.o \
    asmFunc.o \
    asmOutMsg.o \
    
$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) 

%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(EXECUTABLE)
	rm -f $(OBJS)
.PHONY: clean