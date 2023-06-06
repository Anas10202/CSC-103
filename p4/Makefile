SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(wildcard *.h)
TARGETS := rmcomments diagram.svg

COMMON   := -O2 -Wall -Wno-narrowing -DNDEBUG -std=c++11
CFLAGS   := $(CFLAGS) $(COMMON)
CC       := g++
LD       := $(CC)

ifdef skel
IMPL := -skel
endif

all : $(TARGETS)
.PHONY : all

# {{{ for debugging
debug : CFLAGS += -g -O0 -DDEBUG=1 -U NDEBUG -D_GLIBCXX_DEBUG
debug : $(TARGETS)
.PHONY : debug
# }}}

$(OBJECTS) : %.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

diagram.svg : %.svg : %.dot
	dot -Tsvg -o $@ $^

rmcomments : % : %$(IMPL).o
	$(LD) -o $@ $^

.PHONY : clean
clean :
	rm -f $(OBJECTS) $(TARGETS)
