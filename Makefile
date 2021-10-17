CC = g++

EXECUTABLE = stellarlib
SOURCEDIR = src
OBJDIR = obj
BINDIR = bin
LIBS = -lpthread

SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

$(OBJDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) -c -o $@ $<

$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJDIR)/* $(BINDIR)/*
