#ifndef RING_BUFFER_H
#define RING_BUFFER_H

typedef struct ring_buff
{
	uint8_t size;
	uint8_t* address;
	uint8_t head;  
	uint8_t tail;
	uint8_t elements;
} ring_buff;

/*
** Brief: intializes the a ring buffer
**
** param size: deteremines the size of the buffer
**
** ret: struct ring_buff container
*/ 
ring_buff *init_buffer( uint8_t size);

/*
** Brief: adds a byte of data to the start of the ring buffer\
** Overwrites the first bit of data if the buffer is full.
**
** param buffer: refference to the buffer
** param data: data to be added to the buffer
**
** ret: void
*/
void append_buffer(ring_buff *buffer, uint8_t data);

/*
** Brief: Removes the first item stored in the buffer
**
** param buffer: refference to the buffer 
**
** ret: void
*/
void pop_buffer(ring_buff *buffer);

/*
** Brief: Goes through the buffer printing out all of the values, starting from the head of the buffer
**
** param buffer: passing value of buffer struct
**
** ret: void
*/
void print_buffer(ring_buff buffer);


/*
** Brief: Check to see if the buffer is empty
**
** param buffer: passing value of buffer struct
**
** ret: boolean true if empty; else falste
*/
bool is_buffer_empty(ring_buff buffer);

/*
** Brief: Check to see if the buffer is full
**
** param buffer: passing value of buffer struct
**
** ret: boolean true if full; else false
*/
bool is_buffer_full(ring_buff buffer);

/* 
** Brief: Releases the memory stored in the address, does not free the struct container
**
** param buffer: passing reference of buffer to be free
**
** ret: void
*/
void free_buffer(ring_buff **buffer);

#endif