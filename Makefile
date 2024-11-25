ALL: build run

SOURCES := $(wildcard *.c)
EXECUTABLE := rayvaders
OUTPUTFOLDER := bin
WARNINGS := -Wall -Wextra 

# create outputfolder
$(shell mkdir -p $(OUTPUTFOLDER))

build: $(SOURCES)
# gcc -o $(OUTPUTFOLDER)/$(EXECUTABLE) $(SOURCES) -I/opt/homebrew/include -L/opt/homebrew/lib -lraylib -lm
	gcc -o $(OUTPUTFOLDER)/$(EXECUTABLE) $(SOURCES) $(WARNINGS) -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo

clean:
	rm -f $(OUTPUTFOLDER)/$(EXECUTABLE)

run: build
	./$(OUTPUTFOLDER)/$(EXECUTABLE)
