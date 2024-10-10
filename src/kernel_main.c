#include "serial.h"
#include "rprintf.h"


char glbl[128];

unsigned long get_timer_count () {
 unsigned long *timer_count_register = (unsigned long*)0x3f003004 ;
 return * timer_count_register ;
 }

unsigned long timepassed()
{
	int etime = 0;
	int stime = get_timer_count();
	while (etime < stime + 5000000 )
	{
		etime = get_timer_count();
	}
	return etime;
}

unsigned int getEL()
{
	unsigned int el;
asm("mrs %0,CurrentEL"
: "=r"(el)
:
:);
return el>>2;
}



void kernel_main() {
	
	
	// timepassed();
	
	    // int  time = get_timer_count();


	extern char  __bss_start,  __bss_end;

   

	char *bssstart = &__bss_start;
	char *bssend = &__bss_end;
	
	for (char *p = bssstart; p < bssend; p++)
	{
	 	*p = 0xFF;  //test case. // run multiple times in make debug
	 	// *p = 0;
	
	}

	unsigned int current_el = getEL();
	
	putc('b'); 
 	//esp_printf(putc, "Integer test: %d\r\n", 42);
	

	// unsigned int *mu_io = ( unsigned int*)address;

	esp_printf(putc, "Current Execution Level is %d\r\n", current_el);

	while(1) {
	// esp_printf(putc, "%d", *mu_io);
	}
}

