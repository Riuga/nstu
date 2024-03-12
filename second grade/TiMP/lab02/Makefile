all:
	nasm -f elf64 sgn_arr.asm -o sgn_arr.o
	gcc main.c -o main.o -c
	gcc main.o sgn_arr.o -o out -g3 -ggdb