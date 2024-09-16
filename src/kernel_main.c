#include <stdio.h>

char glbl[128];

void kernel_main() {
	extern int __bss_start, __bss_end;
	char *bssstart, *bssend;



	bssstart = (char *) &__bss_start;
	bssend =(char *) &__bss_end;
	

	

	for (char * p = bssstart; p < bssend; ++p )
	{
	
			*p=0;	
			
	}


	struct list_element{
		struct list_element *next;
		int data;
	};

	struct list_element c = {NULL, 0};
	struct list_element b = {&c, 0};
	struct list_element a = {&b, 0};
	struct list_element *head = &a;

	list_add(struct list_element *list_head, struct list_element *new_element);

	void list_add(struct list_element *list_head, struct list_element *new_element){
		struct list_element *current = list_head;

		while (current->next != NULL){
			current = current->next;
		}

		curent->next = new_element;
		new_element->next = NULL;

	}


void list_remove(struct list_element *head, struct list_element *element_to_remove) {
	if (head == NULL || element_to_remove == NULL) {
		return;
		}
	}	

	if (head == element_to_remove {
		struct list_element *new_head = head->next;
			

	free(head);

	head = new_head;

	return;
	}

	struct list_element *current = head;
	while (current->next != NULL && current->next != element_to_remove)
	{
		current = current -> next;
	}

	if (current->next == elelment_to_remove)
	{
		current->next = element_to_remove->next;
	}

	free(element_to_remove);

}
