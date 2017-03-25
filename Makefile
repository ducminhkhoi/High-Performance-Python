SHEDSKIN_LIBDIR=/Users/nguyenkh/anaconda2/lib/python2.7/site-packages/shedskin/lib
CC=g++
CCFLAGS=-O2 -Wno-deprecated $(CPPFLAGS) -I. -I${SHEDSKIN_LIBDIR} -I/usr/local/include -I/opt/local/include -g -fPIC -D__SS_BIND -I/Users/nguyenkh/anaconda2/include/python2.7 -I/Users/nguyenkh/anaconda2/include/python2.7
LFLAGS=-lgc -lpcre $(LDFLAGS) -L/opt/local/lib -L/usr/local/lib -bundle -undefined dynamic_lookup -fno-strict-aliasing

CPPFILES=/Users/nguyenkh/PycharmProjects/High-Performance-Python/shedskinfn.cpp \
	${SHEDSKIN_LIBDIR}/re.cpp \
	${SHEDSKIN_LIBDIR}/builtin.cpp

HPPFILES=/Users/nguyenkh/PycharmProjects/High-Performance-Python/shedskinfn.hpp \
	${SHEDSKIN_LIBDIR}/re.hpp \
	${SHEDSKIN_LIBDIR}/builtin.hpp

all:	shedskinfn.so

shedskinfn.so:	$(CPPFILES) $(HPPFILES)
	$(CC)  $(CCFLAGS) $(CPPFILES) $(LFLAGS) -o shedskinfn.so

clean:
	rm -f shedskinfn.so

.PHONY: all clean

