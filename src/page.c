#include <stdio.h>

struct ppage physical_page_array[128];



void init_pfa_list(void)
{
    for (int i = 0; i <128; i++)
    {
        if (i == 0)
        {
            physical_page_array[i].prev = NULL;
            free_list_head = &physical_page_array[i];
        }  
        else
        {
            physical_page_array[i].prev = &physical_page_array[i -1];
        }

        if (i == 127)
        {
            physical_page_array[i].next = NULL;
        }
  }
}

int main ()
{
    printf("Hello, World!\n");
return 0;
}