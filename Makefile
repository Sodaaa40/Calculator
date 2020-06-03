main: src/main.c src/func.c src/input.c
	gcc src/main.c src/func.c src/input.c -o main `pkg-config --cflags --libs gtk+-2.0` -lm
