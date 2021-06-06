#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "ring_buffer.h"

#define post_error(function_name, reason){\
	printf("ERROR: \n %s \n ", reason);\
	exit(EXIT_FAILURE);\
}

ring_buff *init_buffer( uint8_t size )
{
	ring_buff *buffer = malloc( sizeof(*buffer) );

	if ( buffer == NULL) post_error(create_buffer, "failure to allocate memory to the buffer");

	uint8_t *buff =(uint8_t*)malloc( sizeof(uint8_t) * size+1);

	if ( buff == NULL) post_error(create_buffer, "failure to allocate memory");


	buffer->address		= buff;
	buffer->elements	= 0;
	buffer->head		= 0;
	buffer->tail		= 0;
	buffer->size		= size;

	return (buffer);
}

bool is_buffer_full(ring_buff buffer)
{
	return (buffer.elements  == buffer.size);
}

bool is_buffer_empty(ring_buff buffer)
{
	return (buffer.elements  == 0);
}

void increment_buffer(ring_buff *buffer)
{

	buffer->elements++;
	buffer->tail++;

	/*
	** if the buffer is full, and the tail reaches the end, set tail to begining of memory 
	*/
	if ( buffer->tail > buffer->size)
	{
		buffer->tail =0;
	}
}

void rotate_buffer(ring_buff *buffer)
{
	buffer->tail ++;
	if( buffer->tail > buffer->size)
	{
		buffer->tail = 0;
	}

	buffer->head ++;
	if( buffer->head > buffer->size)
	{
		buffer->head = 0;
	}
}

void append_buffer(ring_buff *buffer, uint8_t data)
{
	if ( buffer->address == NULL) post_error(append_buffer, "buffer was not initalized");
	/*
	**set's the address of the end of the buffer and assigns data
	** starts from 0th position, so we assign, and then increment after
	*/
	uint8_t* address;
	address = buffer->address + buffer->tail;
	*address = data;

	/*
	** if the elements in the ring buffer outgrow the buffer size, overwrite the earliest data
	*/
	if( !is_buffer_full(*buffer)  )
	{
		/*
		** number of elements is within the buffer size
		*/
		increment_buffer(buffer);
	}
	else
	{
		/*
		** The number of elements have outgrown the size of the buffer 
		** -- progress the head and tail of the ring buffer and wrap around, overwriting the earliest data
		*/
		rotate_buffer(buffer);
	}
}

void pop_buffer(ring_buff *buffer)
{
	/*
	** check to see if the buffer is empty
	*/
	if( buffer->elements == 0 ) post_error(pop_buffer,"Buffer is empty");
	
	/*
	** Removing the first bit of data by incremementing the head position of the buffer, and reducing the element count
	*/
	if( buffer->head == buffer->size )
	{
		/*
		** the head will need to wrap around
		*/
		buffer->head =0 ; 
	}
	else
	{
		/*
		** shift head along to the next element
		*/
		buffer->head++;
	}
	//reduce element count
	buffer->elements--;
}

void free_buffer(ring_buff **buffer)
{
	if ( buffer == NULL ) post_error(free_buffer, "There is no buffer to free");

	free((*buffer)->address);
	free(*buffer);
	buffer = NULL;
}

void print_buffer(ring_buff buffer)
{
	uint8_t *address = buffer.address + buffer.head;

	uint8_t k  = buffer.head;
	for( uint8_t i = 0; i < buffer.elements; i++)
	{
		printf ("%i \n ", *address);
		
		address = (address == (buffer.address + buffer.size)) ? buffer.address : address+1; 	
	} 
	printf("\n");
}

