#!/bin/sh

# Compile all .c files into object files
cc -c *.c

# Create a static library from the object files
#  r (replace): Add or replace object files in the archive 
#  c (create): Create the archive if it doesn't exist
#  s (index): Generates an index (symbol table) for faster linking
ar rcs libft.a *.o

# Remove all object files
rm *.o
