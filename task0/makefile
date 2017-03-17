
all: run

run: add.o main.o numbers.o
		gcc -m32 -g -Wall -o run add.o main.o numbers.o

add.o: add.s
		nasm -g -f elf -w+all -o add.o add.s

numbers.o: numbers.c
		gcc -m32 -g -Wall -c numbers.c -o numbers.o

main.o: main.c
		gcc -m32 -g -Wall -c main.c -o main.o

.PHONY: clean

clean:
		rm -f *.o run

