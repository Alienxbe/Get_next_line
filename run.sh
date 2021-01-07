#!/bin/sh

clear
gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=2
./a.out
