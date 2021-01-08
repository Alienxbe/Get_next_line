#!/bin/sh

clear
gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=10
./a.out
