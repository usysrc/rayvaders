ALL: build run

SOURCES := $(wildcard *.c)

build: $(SOURCES)
	gcc -o rayvaders $(SOURCES) -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm

clean:
	rm -f rayvaders

run: build
	./rayvaders
