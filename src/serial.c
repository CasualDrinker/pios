#include <stdint.h>

#include "rprintf.c"
#include "rprintf.h"



// Define the address for the MU_IO register

#define address ((volatile uint32_t *)(0xFE215040))

// Function to send a single character to the serial port
void putc(int data) {
    *address = (uint32_t)data;
}