all: bin/Fifteen-CourseWorkZP bin/Fifteen-CourseWorkZP-test

bin/Fifteen-CourseWorkZP: build/src/fifteen.o build/src/issolvable.o
	g++ -Wall -Werror build/src/fifteen.o build/src/issolvable.o -o bin/Fifteen-CourseWorkZP

build/src/fifteen.o: src/fifteen.cpp
	g++ -Wall -Werror -I src -c src/fifteen.cpp -o build/src/fifteen.o
	
build/src/issolvable.o: src/issolvable.cpp
	g++ -Wall -Werror -I src -c src/issolvable.cpp -o build/src/issolvable.o
	
bin/Fifteen-CourseWorkZP-test: build/test/main.o build/test/test.o build/src/issolvable.o
	g++ -Wall -Werror build/test/main.o build/test/test.o build/src/issolvable.o -o bin/CourseWorkZP-test
	
build/test/main.o: thirdparty/ctest.h
	g++ -Wall -Werror -I thirdparty -c test/main.cpp -o build/test/main.o

build/test/test.o: src/functions.h thirdparty/ctest.h
	g++ -Wall -Werror -I thirdparty -I src -c test/test.cpp -o build/test/test.o
	
testRun:
	./bin/Fifteen-CourseWorkZP-test

clean:
	rm -rf build/test/*.o build/src/*.o bin/Fifteen-CourseWorkZP bin/Fifteen-CourseWorkZP-test
	

.PHONY: all clean
