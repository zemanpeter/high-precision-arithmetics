program=test
OBJ=hp_int_manip.o test.o
.PHONY: build
.PHONY: clean

build: $(program)

clean:
	rm -f *.o $(program)

${program}: ${OBJ}
	g++ $(OBJ) -o $(program)

hp_int_manip.o: hp_int_manip.cpp
	g++ -c hp_int_manip.cpp

test.o: test.cpp hpa.h
	g++ -c test.cpp
