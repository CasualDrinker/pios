#include <stdio.h>
// Define the struct for list elements
struct list_element {
    struct list_element* next;
    int data;
};

//global list_elements
struct list_element c = { NULL, 30 }; // End of list: next pointer is NULL, data is 30
struct list_element b = { &c, 20 };   // b points to c, data is 20
struct list_element a = { &b, 10 };   // a points to b, data is 10
struct list_element* head = &a;

// Function to print the list
void print_list(struct list_element* node) {
    printf("** Start List **\n");
    while (node != NULL) {
        printf("Data: %d\n", node->data);
        node = node->next;
    }
    printf("** End List **\n");
}

void list_add(struct list_element** list_head, struct list_element* new_element, int position) {
    if (position < 1) {
        printf("Position can't be less than 1\n");
        return;
    }

    struct list_element* current = *list_head;
    struct list_element* previous = NULL;
    int i = 1;

    // Traverse the list to find the position
    while (i < position && current != NULL) {
        previous = current;
        current = current->next;
        i++;
    }

    //insert new element
    if (position == 1) {
        // Insert at the head
        new_element->next = *list_head;
        *list_head = new_element;
    }
    else if (previous != NULL) {
        // Insert after previous node
        previous->next = new_element;
        new_element->next = current;
    }
 
    
}

void list_remove(struct list_element* element) 
{
    int position = 1;
    if (element == NULL) {
        printf("Element is NULL.\n");
        return;
    }

    struct list_element* current = head;  // head is accessed from global
    struct list_element* previous = NULL;

    // Traverse the list to find the element to remove
    while (current != NULL && current != element) {
        previous = current;
        current = current->next;
        position++;
    }

    // If the element was not found
    if (current == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    // Adjust pointers
    if (previous == NULL) {
        // Removing the head element
        head = current->next;  // Update head
    }
    else {
        previous->next = current->next;  // Bypass the current element
    }

    printf("** Removed element with value %d. **\n", current->data);
    printf("** Removed position %d. **\n", position);
}

int main() {




    struct list_element test = { NULL, 5 };
    struct list_element test2 = { NULL, 55 };
    struct list_element test3 = { NULL, 555 };
    struct list_element test4 = { NULL, 5555 };
    struct list_element test5 = { NULL, 55555 };

    list_add(&head, &test, 1); //adding element test to 1st position
   list_add(&head, &test2, 2); //adding element test2 to 2nd position
    list_add(&head, &test3, 4);
    list_add(&head, &test4, 10000); //adding element test4 10000th position. It just adds to the end of list. increasing list by 1
     list_add(&head, &test5, 100000);
     // list_add(&head, &test5, 1); //creates print loop



     

    print_list(head); // Print the list
    
    list_remove(&test2); //removes element with value 55, which is test2's value.

    print_list(head);

    return 0;
} 