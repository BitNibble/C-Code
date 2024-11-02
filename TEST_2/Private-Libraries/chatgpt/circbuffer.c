/******************************************************************************
    CIRCBUFFER
Author: Sergio Santos
    <sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 07092022
Comment:
    Circular Buffer
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "circbuffer.h"

/*** Function Prototypes ***/
static uint8_t CIRC_get(struct circ_buf_template* circ);
static void CIRC_put(struct circ_buf_template* circ, uint8_t data);
static void CIRC_string(struct circ_buf_template* circ, const char* str);

/******************************************************************************/
// Enable the circular buffer
circbuff CIRCBUFFenable(uint8_t size_buff, uint8_t* buff) {
    // Initialize circular buffer object
    struct circ_buf_template circ = {0};  // Zero-initialize to avoid garbage values

    // Set up buffer parameters
    circ.tail = circ.head = buff;          // Initialize head and tail to the start of the buffer
    circ.orig = buff;                     // Original pointer to the start of the buffer
    circ.end = buff + size_buff;          // Pointer to the end of the buffer

    // Assign function pointers
    circ.get = CIRC_get;
    circ.put = CIRC_put;
    circ.string = CIRC_string;

    return circ; // Return the initialized circular buffer
}

/******************************************************************************/
// Get a byte from the circular buffer
uint8_t CIRC_get(struct circ_buf_template* circ) {
    if (circ->tail == circ->head) { // Buffer is empty
        return 0; // Return 0 (or some error value) if the buffer is empty
    }

    uint8_t value = *circ->tail;  // Get the value at the tail
    circ->tail++;                  // Move tail forward

    // Wrap around if necessary
    if (circ->tail == circ->end) {
        circ->tail = circ->orig;   // Wrap around to the beginning
    }

    return value; // Return the retrieved value
}

/******************************************************************************/
// Put a byte into the circular buffer
void CIRC_put(struct circ_buf_template* circ, uint8_t data) {
    uint8_t* next = circ->head + 1; // Calculate the next head position

    // Wrap around if necessary
    if (next == circ->end) {
        next = circ->orig; // Wrap around to the beginning
    }

    // Check for overflow
    if (next == circ->tail) {
        // Buffer is full, cannot add data (add error handling if needed)
        return;
    }

    *circ->head = data; // Write data to the buffer
    circ->head = next;  // Move head forward
}

/******************************************************************************/
// Put a string into the circular buffer
void CIRC_string(struct circ_buf_template* circ, const char* str) {
    while (*str) { // Loop until the end of the string
        CIRC_put(circ, *str++); // Put each character in the circular buffer
    }
}

/******************************************************************************/
// Interrupt handling code (if applicable)
/******************************Comment****************************************
*******************************************************************************/
/***EOF***/
