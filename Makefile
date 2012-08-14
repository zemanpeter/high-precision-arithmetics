program=test
OBJ=hp_uint_manip.o hp_uint_cmp.o hp_uint_as.o hp_uint_mult.o hp_uint_dm.o hp_uint_exp.o hp_int.o $(program).o

build: $(program)

clean:
	rm -f *.o $(program)

$(program): $(OBJ)
	g++ $(OBJ) -o $(program)

hp_uint_manip.o: hp_uint_manip.cpp
	g++ -c -fpermissive hp_uint_manip.cpp

hp_uint_cmp.o: hp_uint_cmp.cpp
	g++ -c hp_uint_cmp.cpp

hp_uint_as.o: hp_uint_as.cpp
	g++ -c hp_uint_as.cpp

hp_uint_mult.o: hp_uint_mult.cpp
	g++ -c hp_uint_mult.cpp

hp_uint_dm.o: hp_uint_dm.cpp
	g++ -c hp_uint_dm.cpp

hp_uint_exp.o: hp_uint_exp.cpp
	g++ -c hp_uint_exp.cpp

hp_int.o: hp_int.cpp
	g++ -c -fpermissive hp_int.cpp

$(program).o: $(program).cpp hpa.h hp_int.h hp_uint.h
	g++ -c $(program).cpp
