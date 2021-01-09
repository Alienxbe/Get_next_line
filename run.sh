#!/bin/sh

clear
gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=100 -g -fsanitize=leak
./a.out
