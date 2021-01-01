#!/bin/sh

gcc -Wall -Wextra -Werror *.c -D BUFFER_SIZE=5
./a.out
