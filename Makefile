# Compiler Configs

CC = g++
OPT = -O0
CFLAGS = -Wall -Wextra -std=c++17 $(OPT) $(DEPFLAGS)

# Paths

INCDIRS = .
CODEDIRS = .
BINARY = NumberGuessingGame

# Makefile Vars Generation
INCLUDES = $(foreach D,$(INCDIRS),$(wildcard $(D)/*.hpp))

SRCFILES = $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))
OBJECTS = $(SRCFILES:.cpp=.o)

DEPFLAGS = -MP -MMD
DEPFILES = $(SRCFILES:.cpp=.d)

-include $(DEPFILES)

# Rules

.PHONY: all clean

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES) *.hpp.gch

