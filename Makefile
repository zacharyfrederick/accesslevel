DEPS = accesslevel.h

testmake: accesslevel.c
	cc -c accesslevel.c
	ar cr libaccesslevel.a accesslevel.o
