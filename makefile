all: bin/Fifteen-CourseWorkZP

bin/Fifteen-CourseWorkZP: build/src/fifteen.o
	g++ -Wall -Werror build/src/fifteen.o -o bin/Fifteen-CourseWorkZP

build/src/fifteen.o: src/fifteen.cpp
	g++ -Wall -Werror -I src -c src/fifteen.cpp -o build/src/fifteen.o

clean:
	rm -rf build/test/*.o build/src/*.o bin/Fifteen-CourseWorkZP

.PHONY: all clean
