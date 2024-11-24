ALL: build run

build: main.c
	gcc -o rayvaders main.c game.c ship.c bullet.c -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm

clean:
	rm -f rayvaders

run: build
	./rayvaders
