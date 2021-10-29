CC = gcc
CFLAGS = -Wall -g

RUN = src
TARGET = out

C_SOURCE := $(shell find $(RUN) -name *.c)

all:
	$(CC) $(CFLAGS) $(C_SOURCE) -o $(TARGET) -lm
	./$(TARGET)

clean:
	rm -rf $(TARGET)
	rm -rf *.o