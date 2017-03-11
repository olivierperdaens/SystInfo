build :
	gcc -g -Wall -W -Werror -std=gnu99 -c matrix.c
	gcc -g -Wall -W -Werror -std=gnu99 -c test.c -lcunit
	gcc -o test test.o matrix.o -lcunit
