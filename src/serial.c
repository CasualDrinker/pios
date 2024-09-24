#include "rprintf.h"

//getting MU_IO address
#define address 0x3F215040

int putc(int data) {
     unsigned int *mu_io = ( unsigned int*)address;
    *mu_io = (unsigned int)data; 
    return 0;
}

