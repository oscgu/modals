.POSIX:
CC = cc
CFLAGS = -pedantic -Wall -Os -s -Wno-deprecated-declarations -std=c99 -lX11
DEPS = notif.h
OBJ = example.o notif.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -rf *.o