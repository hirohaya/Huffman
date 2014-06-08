CC=gcc
CFLAGS=-c -ansi -pedantic -Wall -g #-O2
LDFLAGS=
SOURCES= main.c tree.c character.c list.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=compactador

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:          
	rm -f *o $(EXECUTABLE)

