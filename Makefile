all: bin/calc bin/calc-test

bin/calc: build/src/main.o build/src/input.o build/src/calc.o build/src/func.o
	gcc -Wall -Werror build/src/main.o build/src/func.o build/src/input.o build/src/calc.o -o bin/calc `pkg-config --cflags --libs gtk+-2.0` -lm

build/src/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/src/main.o `pkg-config --cflags --libs gtk+-2.0`

build/src/func.o: src/func.c
	gcc -Wall -Werror -c src/func.c -o build/src/func.o `pkg-config --cflags --libs gtk+-2.0`

build/src/input.o: src/input.c
	gcc -Wall -Werror -c src/input.c -o build/src/input.o `pkg-config --cflags --libs gtk+-2.0`

build/src/calc.o: src/calc.c
	gcc -Wall -Werror -c src/calc.c -o build/src/calc.o -lm

bin/calc-test: build/test/main.o build/test/calculation.o build/src/calc.o
	gcc -Wall -Werror build/test/main.o build/test/calculation.o build/src/calc.o -o bin/calculation-test -lm

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/calculation.o: test/calculation.c
	gcc -I thirdparty -Wall -Werror -c test/calculation.c -o build/test/calculation.o `pkg-config --cflags --libs gtk+-2.0` -lm
