#Compilers
CC          := g++ -std=c++14 -Wno-psabi -lwiringPi -lwiringPiDev
DGEN        := doxygen

#The Target Binary Program
TARGET      := libelma.a

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := ./src
INCDIR      := ./include
BUILDDIR    := ./build
TARGETDIR   := ./lib
SRCEXT      := cc

#Flags, Libraries and Includes
CFLAGS      := -fsanitize=address -ggdb
LIB         := -lgtest -lpthread -lasan -lbcm2835
INC         := -I$(INCDIR)
INCDEP      := -I$(INCDIR)

#Files
DGENCONFIG  := docs.config
HEADERS     := $(wildcard $(INCDIR)/*.h)
SOURCES     := $(wildcard $(SRCDIR)/*.cc)
OBJECTS     := $(patsubst %.cc, $(BUILDDIR)/%.o, $(notdir $(SOURCES)))

#Defauilt Make
all: directories $(TARGETDIR)/$(TARGET) projectSrcs
	echo $(SOURCES) $(HEADERS)

#Remake
remake: cleaner all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

projectSrcs:
	cd projectSrc && $(MAKE)


docs: docs/index.html

docs/index.html: $(SOURCES) $(HEADERS) README.md docs.config dox/* projectSrc/*.cc
	$(DGEN) $(DGENCONFIG)
	cp .nojekyll docs

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)/*.o
	cd projectSrc && $(MAKE) clean

#Full Clean, Objects and Binaries
spotless: clean
	@$(RM) -rf $(TARGETDIR)/$(TARGET) *.db
	@$(RM) -rf build lib docs/*
	cd projectSrc && $(MAKE) spotless

#Link
$(TARGETDIR)/$(TARGET): $(OBJECTS) $(HEADERS)
	ar rvs $@ $(OBJECTS)
	
#Compile
$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c -fPIC -o $@ $<
