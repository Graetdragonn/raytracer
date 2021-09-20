CC = gcc
CXX = g++
ECHO = echo
RM = rm -f

#TERM = "\"S2021\""

# Flags for gcc and g++ compilers
# -D defines TERM macro in code
CFLAGS = -Wall -Werror -ggdb3 -funroll-loops #-DTERM=$(TERM)
CXXFLAGS = -Wall -Werror -ggdb3 -funroll-loops #-DTERM=$(TERM)

# Libraries to link in
#LDFLAGS = -lncurses

BIN = main
OBJS = main.o sphere.o

all: $(BIN) #etags

$(BIN): $(OBJS)
	@$(ECHO) Linking $@
	@$(CXX) $^ -o $@ #$(LDFLAGS)

-include $(OBJS:.o=.d)

%.o: %.c
	@$(ECHO) Compiling $<
	@$(CC) $(CFLAGS) -MMD -MF $*.d -c $<

%.o: %.cpp
	@$(ECHO) Compiling $<
	@$(CXX) $(CXXFLAGS) -MMD -MF $*.d -c $<

.PHONY: all clean clobber etags

clean:
	@$(ECHO) Removing all generated files
	@$(RM) *.o $(BIN) *.d TAGS core vgcore.* gmon.out

clobber: clean
	@$(ECHO) Removing backup files
	@$(RM) *~ \#* *pgm

#Used in Emacs to better search defined functions in code etc.
etags:
	@$(ECHO) Updating TAGS
	@etags *.[ch] *.cpp
