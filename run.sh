#!/bin/sh

gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=50
./a.out
