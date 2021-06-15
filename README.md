# ring_buffer
A simple ring buffer written in C.

The functions for the ring buffer are stored in ring_buffer.c and are designed to be used as an external library through the inclusion of ring_buffer.h, and pointing the compiler to ring_buffer.c

<h1>Requirements: </h1>
GCC

<h1>Example of use: </h1>
For an example of how to use please see example.c and can be compiled using GCC on Linux using :

GCC example.c ring_buffer.c -o example

The CMake file will compile the test program used to test the correctness of the program.



