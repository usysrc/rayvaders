ALL: build run

SOURCES := $(wildcard *.c)
EXECUTABLE := rayvaders
OUTPUTFOLDER := bin

# create outputfolder
$(shell mkdir -p $(OUTPUTFOLDER))

build: $(SOURCES)
	gcc -o $(OUTPUTFOLDER)/$(EXECUTABLE) $(SOURCES) -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm

clean:
	rm -f $(OUTPUTFOLDER)/$(EXECUTABLE)

run: build
	./$(OUTPUTFOLDER)/$(EXECUTABLE)
