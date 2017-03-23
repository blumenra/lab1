
all: my_echo

my_echo: my_echo.o
	gcc -g -m32 -Wall my_echo.o -o my_echo

my_echo.o: my_echo.c
	gcc -g -m32 -Wall -c my_echo.c -o my_echo.o

.PHONY:
	clean

clean:
	rm -f *.o my_echo