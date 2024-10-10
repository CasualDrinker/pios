#include <stdio.h>
#include "page.h"

struct ppage physical_page_array[128];

struct ppage* list = NULL;


void init_pfa_list(void)
{
    for (int i = 0; i < 128; i++)
    {
        if (i == 0) {
            physical_page_array[i].prev = NULL;         
            list = &physical_page_array[i];  
        }
        else {
            physical_page_array[i].prev = &physical_page_array[i - 1];  
        }

        if (i == 127) {
          
            physical_page_array[i].next = NULL;       
        }
        else {
            physical_page_array[i].next = &physical_page_array[i + 1];  
        }

        physical_page_array[i].physical_addr = NULL;  
    }
}

struct ppage* allocate_physical_pages(unsigned int npages) {
    struct ppage* current = list;
    struct ppage* start = NULL;
    unsigned int count = 0;

    while (current != NULL) {
        if (count == 0) {
            start = current;  
        }
        count++;

        if (count == npages) {
            if (start->prev) {
                start->prev->next = current->next;
            }
            else {
             
                list = current->next;
            }

            if (current->next) {
                current->next->prev = start->prev;
            }
            start->prev = NULL;
            current->next = NULL;

            return start;  
        }

        current = current->next;
    }

    return NULL; 
}


void free_physical_pages(struct ppage* ppage_list) {
    struct ppage* current = ppage_list;

    
    while (current != NULL) {
        struct ppage* next = current->next;

        
        current->next = list;
        if (list != NULL) {
            list->prev = current;
        }
        list = current;
        current->prev = NULL;  

        current = next; 
    }
}


int main ()
{
    printf("Hello, World!\n");
return 0;
}