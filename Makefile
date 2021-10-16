CC = g++

EXECUTABLE = stellarlib
SOURCEDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


$(OBJECTS): $(OBJDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) -c -o $@ $<

$(BINDIR)/$(EXECUTABLE): $(OBJ)
	$(CC) -o bin/$@ $^

clean:
	rm -f bin/* build/*
