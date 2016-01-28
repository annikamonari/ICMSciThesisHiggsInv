CC := g++ # Main compiler
ROOTSYS := /Applications/root_v5.34.34/
DYLD_LIBRARY_PATH := $ROOTSYS/lib/home/hep/dsg12/TMVA-v4.2.0/
TMVASYS := /home/hep/dsg12/TMVA-v4.2.0
SRCDIR := src
BUILDDIR := build
TARGET := bin/main # Main executable of project-- type 'make' and this gets built.
 
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT)) # dynamic, includes any file with .cpp extension

# OBJECTS - build object list based on available sources
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o)) 
CFLAGS := -g -Wall -w $(inherited) `root-config --cflags`
LDFLAGS := $(inherited) `root-config --libs --glibs  --cflags` -L$(TMVASYS)/lib -lTMVA.1 -lMLP -lMinuit -lXMLIO -lTreePlayer  
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
