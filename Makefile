CC := g++ # Main compiler

SRCDIR := src
BUILDDIR := build
TARGET := bin/main # Main executable of project-- type 'make' and this gets built.
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)) # dynamic, includes any file with .cpp extension

# OBJECTS - build object list based on available sources
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o)) 
CFLAGS := -g -Wall -pedantic `root-config --cflags`
LDFLAGS := `root-config --libs --cflags`
INC := -I include # ensures all header files are acessible

# use echos to make sure commands are running

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) $(LDFLAGS) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Compiling..."
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning..." 
	$(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean