#!/bin/sh

cc -c *.c
ar rc libft.a *.o
rm *.o
ranlib libft.a
