CC = gcc
CFLAGS = -Wall -O2
SRC = src/main.c
TARGET = program.exe

all: $(TARGET)

# from:
$(TARGET): src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c

# to:
$(TARGET): src/main.c src/interface.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c src/interface.c

clean:
	del $(TARGET)