CC = gcc
CFLAGS = -Wall -O2
SRC = main.c
TARGET = program

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -rf $(TARGET)