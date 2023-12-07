CC = gcc
CFLAGS = -Wall -Wextra -I$(INCDIR)
LDFLAGS = -lm

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
EXECUTABLE = $(BINDIR)/main

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ) | $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) $(BINDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)
