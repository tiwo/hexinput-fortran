#!/usr/bin/make --file

all: hextest hexout

hextest: hexin.o hextest.f
hexout: hexout.f

clean:
	rm -f hextest hexout *.o
