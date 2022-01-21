all: bin/Fifteen-CourseWorkZP

bin/Fifteen-CourseWorkZP: build/src/fifteen.cpp
	gcc -Wall -Werror build/src/fifteen.cpp

build/src/main.o: src/fifteen.cpp
	gcc -Wall -Werror -I src -c src/main.c -o build/src/fifteen.cpp

clean:
	rm -rf build/test/*.o build/src/*.o bin/Fifteen-CourseWorkZP bin/Fifteen-CourseWorkZP-test

.PHONY: all clean