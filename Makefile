# Compiler Configs

CC = g++
OPT = -O0
CFLAGS = -Wall -Wextra -g $(INCLUDES) $(OPT) $(DEPFLAGS)

# Paths

INCDIRS = .
CODEDIRS = .
BINARY = NumberGuessingGame

# Makefile Vars Generation
INCLUDES = $(foreach D,$(INCDIRS),$(wildcard $(D)/*.hpp))

SRCFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS = $(patsubst %.cpp,%.o,$(SRCFILES))

DEPFLAGS = -MP -MMD
DEPFILES = $(patsubst %.cpp,%.d,$(SRCFILES))

-include $(DEPFILES)

# Rules

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< $@

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) *.hpp.gch

