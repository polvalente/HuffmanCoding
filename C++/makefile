CC=g++
LD=g++

CFLAGS=-std=c++03 -Wall -Werror
LFLAGS=-std=c++03

OBJDIR=./obj
SRCDIR=./src

DIRLIST=$(OBJDIR)\
	$(SRCDIR)

OBJNAMES=main.o

OBJS=$(addprefix $(OBJDIR)/, $(OBJNAMES))

EXEC=Huffman

.PHONY: all clean prep remake

all: prep $(EXEC)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC): $(OBJS)
	$(LD) -o $(EXEC) $(OBJS) $(LFLAGS)

clean:
	rm -f $(EXEC) $(OBJS)

prep:
	mkdir -p $(DIRLIST)

remake: clean all

