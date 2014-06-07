CC=gcc
CFLAGS=-c -ansi -pedantic -O2 -Wall -g
LDFLAGS=
SOURCES= main.c tree.c character.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=compressor

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:          
	rm -f *o $(EXECUTABLE)

