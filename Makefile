# Makefile for Lab5 project
CC = gcc
CFLAGS = -Wall -Werror -std=c99
LDFLAGS = -lsqlite3
BINDIR = bin
INCDIR = include
SRCDIR = src
OBJDIR = obj


main: main.o database.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJDIR)/main.o $(OBJDIR)/database.o -o $(BINDIR)/$@

main.o: $(SRCDIR)/main.c $(INCDIR)/database.h
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

database.o: $(SRCDIR)/database.c $(INCDIR)/database.h
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/main