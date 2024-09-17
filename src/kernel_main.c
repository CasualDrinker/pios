
char glbl[128];

void kernel_main() {
	
	extern char  __bss_start,  __bss_end;

   

	char *bssstart = &__bss_start;
	char *bssend = &__bss_end;
	
	for (char *p = bssstart; p < bssend; p++)
	{
	/*	*p = 0xFF;  //test case.*/ // run multiple times in make debug
		*p = 0;
	
	}


 	
    
}

