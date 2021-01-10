#!/bin/sh

clear
gcc -Wall -Wextra -Werror Basic/*.c main.c -D BUFFER_SIZE=100000
./a.out
