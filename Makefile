program=test
OBJ=hp_uint_manip.o hp_uint_cmp.cpp hp_uint_as.cpp test.o
.PHONY: build
.PHONY: clean

build: $(program)

clean:
	rm -f *.o $(program)

$(program): $(OBJ)
	g++ -g $(OBJ) -o $(program)

hp_uint_manip.o: hp_uint_manip.cpp
	g++ -g -c -fpermissive hp_uint_manip.cpp

hp_uint_cmp.o: hp_uint_cmp.cpp
	g++ -g -c hp_uint_cmp.cpp

hp_uint_as.o: hp_uint_as.cpp
	g++ -g -c hp_uint_as.cpp

test.o: test.cpp hp_uint.h
	g++ -g -c test.cpp
