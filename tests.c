#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "ring_buffer.h"

#include <assert.h>


/*
** small fucntion for summing over all values in the buffer
*/
int sum_buffer(ring_buff buffer){
	uint8_t *address = buffer.address + buffer.head;

	uint8_t k  = buffer.head;

	int sum = 0;
	
	for( uint8_t i = 0; i < buffer.elements; i++)
	{
		sum += *address;
		address = (address == (buffer.address + buffer.size))? buffer.address : address+1 ; 
	} 

	return sum;
}

int main()
{
	printf(" Running \n");


	/*
	** initalize buffer
	*/
	ring_buff *buffer ;
	buffer = init_buffer( 7 );

	/*
	** append single test
	*/
	append_buffer(buffer, 32 );

	assert(sum_buffer(*buffer) == 32 ) ; 
	
	printf(" single append test: Complete\n");

	/*
	**  pop single test
	*/
	pop_buffer(buffer);

	assert(sum_buffer(*buffer) == 0);

	
	printf(" single pop test: Complete\n");

	/*
	** append and sum 0->7
	*/
	for (uint8_t i = 0 ; i< 7; i++)
	{
		append_buffer(buffer, i);
	}

	assert( sum_buffer(*buffer) == 21);
	
	printf(" appending 0->7: Complete\n");

	/*
	** appending 21 to the buffer drops 0 from the begginig
	*/
	append_buffer(buffer, 15);
	assert( sum_buffer(*buffer) == 21+15);

	printf(" appending 15: Complete\n");


	/*
	** appending 18 to the buffer drops 1 from the beginning
	*/
	append_buffer(buffer, 18);
	assert( sum_buffer(*buffer) == 21+15+18-1);

	printf(" appending 18: Complete\n");

	print_buffer(*buffer);

	/*
	** drop the first 4 data points from the buffer ( 2 ,3 ,4 ,5)
	*/
	for( int i = 0 ; i < 4; i++) pop_buffer(buffer);

	assert( sum_buffer(*buffer) == 21+15+18-1-2-3-4-5);

	
		
	printf(" removing first 4 elements: Complete\n");


	for ( int i = 0; i < 3; i ++) pop_buffer(buffer);
	assert( sum_buffer(*buffer) == 0);

		
	printf(" Emptying buffer: Complete\n");


	free_buffer(&buffer);

	//assert(buffer==NULL);
	printf(" tests are complete\n");

}