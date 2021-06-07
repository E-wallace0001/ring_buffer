# ring_buffer
A simple ring buffer written in C

Requirements:
GCC

For an example of how to use please see example.c and can be compiled using GCC on Linux using :

GCC example.c ring_buffer.c -o example

The CMake file will compile the test program used to test the correctness of the program.
Instructions for the CMake in Linux:

Download the repositiory.

in the termnical, CD to the containing directory type : 

mkdir build

cd build

cmake ..

cmake --build ./


Will compile the program to 'tests' in the build folder and can be run using ./tests



