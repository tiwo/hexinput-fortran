#!/usr/bin/make --file

# Makefile for "hexinput-fortran"
#
# relies on the implicit rules of make (tested with GNU make)
# that use $(FC) to compile Fortran. On my system, $(FC) is "f77",
# but only FORTRAN 95 is installed. But
#
#    make FC=f95 [target]
#
# works.

all: hextest hexout

hextest: hexin.o hextest.f
hexout: hexout.f

clean:
	rm -f hextest hexout *.o
