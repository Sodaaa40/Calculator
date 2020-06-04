#main: src/main.c src/func.c src/input.c
	#gcc src/main.c src/func.c src/input.c src/calc.c -o main `pkg-config --cflags --libs gtk+-2.0` -lm
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
