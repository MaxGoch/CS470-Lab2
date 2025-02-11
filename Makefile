#Define the C compiler to use
CC=gcc

#Define any compile-time flag
CFLAGS=-Wall -g

TARGET=lab2

all: $(TARGET)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
