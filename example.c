#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "ring_buffer.h"

int main()
{
	printf(" Running \n");


	/*
	** initalize buffer
	*/
	ring_buff *buffer = init_buffer( 7 );

	/*
	** fill buffer
	*/
	for (uint8_t i =0 ; i <7; i++)
	{
		append_buffer(buffer, i );
	}

	printf(" size of buffer: %i \n", buffer->elements);

	/*
	** prints all data in buffer
	*/
	print_buffer(*buffer);

	/*
	** removes the earliest element of the buffer
	*/
	pop_buffer(buffer);

	printf(" size of the buffer %i \n", buffer->elements);
	
	print_buffer(*buffer);

	free_buffer(&buffer);


	printf("completed \n ");
	exit(EXIT_SUCCESS);

}