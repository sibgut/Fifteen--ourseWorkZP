all: bin/Fifteen-CourseWorkZP bin/Fifteen-CourseWorkZP-test

bin/Fifteen-CourseWorkZP: build/src/fifteen.o  

	gcc -Wall -Werror build/src/fifteen.o -o bin/Fifteen-CourseWorkZP

builfifteen/src/fifteen.o: src/fifteen.cpp
	gcc -Wall -Werror -I src -c src/fifteen.cpp -o build/src/fifteen.o

clean:
	rm -rf build/test/*.o build/src/*.o bin/Fifteen-CourseWorkZP bin/Fifteen-CourseWorkZP-test

.PHONY: all clean