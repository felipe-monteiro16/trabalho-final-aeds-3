CC = gcc
CFLAGS = -Wall -O2
TARGET = program.exe

all: $(TARGET)

# Regra única: compila main, interface e labirinto juntos
$(TARGET): src/main.c src/interface.c src/labirinto.c
	$(CC) $(CFLAGS) -o $(TARGET) src/main.c src/interface.c src/labirinto.c

clean:
	del $(TARGET)