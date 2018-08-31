#
# Makefile that builds btest and other helper programs for the CS:APP data lab
# 
CC = gcc
CFLAGS = -O -Wall -m32
LIBS = -lm

VERSION = 2
HANDINDIR = /users/groups/cs224ta/datalab

all: btest fshow ishow

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c

fshow: fshow.c
	$(CC) $(CFLAGS) -o fshow fshow.c

ishow: ishow.c
	$(CC) $(CFLAGS) -o ishow ishow.c

# Forces a recompile. Used by the driver program. 
btestexplicit:
	$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c 

handin:
	install -m660 bits.c $(HANDINDIR)/$(USER)-$(VERSION)-bits.c

clean:
	rm -f *.o btest fshow ishow *~


