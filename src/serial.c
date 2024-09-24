

#include "rprintf.c"
#include "rprintf.h"


//getting MI_IO address
#define address 0xFE215040

void putc(int data) {
     unsigned int *mu_io = ( unsigned int*)address;
    *mu_io = (unsigned int)data; 
}