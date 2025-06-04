/******************************************************************************
    CIRCBUFFER
Author: Sergio Santos
    <sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 03112024
Comment:
    Circular Buffer
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "..\inc\circbuffer.h"
/******************************************************************************/
// Get a byte from the circular buffer
char CIRC_get(circbuff* circ) {
	char value = *circ->par.head;
    if (circ->par.tail != circ->par.head) {
    	value = *circ->par.tail;
    	circ->par.tail++;
    	// Wrap around if necessary
    	if (circ->par.tail == circ->par.end) {
     	   circ->par.tail = circ->par.orig;
    	} 
	}
    return value;
}
/******************************************************************************/
// Put a byte into the circular buffer
void CIRC_put(circbuff* circ, char data) {
    char* next = circ->par.head + 1;
    // Wrap around if necessary
    if (circ->par.head == circ->par.end) {
		circ->par.head = circ->par.orig;
		next =  circ->par.head + 1;
	}
	*circ->par.head = data;
	circ->par.head = next;
	*next = 0;
}
/******************************************************************************/
// Get a string from the circular buffer
void CIRC_gets(circbuff* circ, char* str) {
	for( *str = CIRC_get(circ); *str++; *str = CIRC_get(circ) );	// Get each character in the circular buffer
}
/******************************************************************************/
// Put a string into the circular buffer
void CIRC_puts(circbuff* circ, const char* str) {
	for( CIRC_put( circ, *str ); *str++; CIRC_put( circ, *str ) ); // Put each character in the circular buffer
}
/******************************************************************************/
// Enable the circular buffer
struct circ_buf_template CIRCBUFFenable(size_t size_buff, char* buff) {
    // Initialize circular buffer object
    struct circ_buf_template circ = {0};  // Zero-initialize to avoid garbage values

    // Set up buffer parameters
    circ.par.tail = circ.par.head = buff;	// Initialize head and tail to the start of the buffer
    circ.par.orig = buff;					// Buffer pointer
    circ.par.end = buff + size_buff;		// Pointer end buffer flag

    // Assign function pointers
    circ.get = CIRC_get;
    circ.put = CIRC_put;
    circ.gets = CIRC_gets;
    circ.puts = CIRC_puts;

    return circ; // Return the initialized circular buffer
}
/*******************************************************************************/

/***EOF***/

