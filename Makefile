OUT	= pp
LFLAGS = -lm -Wall -O3

all: pp

pp: build/main.o
	$(CC) -o $@ $^ $(LFLAGS)

build/main.o: src/main.c
	$(CC) -c -o $@ $^ $(LFLAGS)

clean:
	rm -f build/main.o $(OUT)
