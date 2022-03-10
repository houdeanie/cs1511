// write code for a program to delete first element, delete last elelment, delete selected element, and reverse a list
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 12 lab

// mostly given, need to write functions for delete_first, delete_last, delete_contains and reverse
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int       data;
};
// declaring functions for main function, struct functions are weird
struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
struct node *delete_first(struct node *head);
struct node *delete_last(struct node *head);
struct node *delete_contains(int i, struct node *head);
void print_list(struct node *head);
struct node *reverse(struct node *list);

#define MAX_LINE 4096

// simple main function to test delete_first, delete_last, delete_contains, reverse

int
main(int argc, char *argv[]) {
    char line[MAX_LINE];
    struct node *list_head = NULL;

    while (1) {
        printf("list = ");
        print_list(list_head);
        printf("\n");

        printf("> ");
        if (fgets(line, MAX_LINE, stdin) == NULL) {
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "quit") == 0) {
            return 0;
        } else if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
        } else if (strcmp(line, "delete_first") == 0) {
            list_head = delete_first(list_head);
        } else if (strcmp(line, "delete_last") == 0) {
            list_head = delete_last(list_head);
        } else if (strcmp(line, "delete_contains") == 0) {
            list_head = delete_contains(argument, list_head);
        } else if (strcmp(line, "reverse") == 0) {
            list_head = reverse(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }
    }
}

// delete first node in list

struct node *delete_first(struct node *head) {
    // if nothing in the list
    if (head == NULL) {
    	return NULL;
    }
    // if there is something in the list
    struct node *n = head;
    head = head->next; // move head to the second element, new head is the second element
    // n is still at the first element
    n->next = NULL; // pointer to the next element is now NULL, separateting the first element
    
    // if there is only one element in the list
    if (n == head) {// but generally covered in the above code
    	head = NULL;
    }
    free(n);
    return head;
}

// delete last node in list

struct node *delete_last(struct node *head) {
    // if no list
    if (head == NULL) {
    	return NULL;
    }
    // if more than one element in the list
    struct node *n = head;
    struct node *last = NULL;
    while (n->next != NULL) { // finding last element
    	last = n; // placeholder for second last
    	n = n->next;
    }
    if (last != NULL) { // make second last the last
    	last->next = NULL;
    }
    if (n == head) { // if only one element
    	head = NULL;
    }
    free(n);
    return head;
}

// delete first node containing specified int

struct node *delete_contains(int i, struct node *head) {
    if (head == NULL) { // if no list
    	return NULL;
    }
    if (head->data == i) { // if the first element is the specified element
    	head = delete_first(head);
    	return head;
    }
    // if more than one in the list
    struct node *n = head;
    struct node *previous = head;
    while (n != NULL) {
    	if (n->data == i) { // if match
			previous->next = n->next; // skip and set n to NULL
			n = NULL;
			free(n);
			break;
		}	
		previous = n;
		n = n->next;
	}
    return head;
}

// reverse the nodes in list

struct node *reverse(struct node *head) {
	if (head == NULL) { // if no list
        return NULL;
    }
    if (head->next == NULL) { // if only 1 element
        return head;
    }
    // if more than 1 element
    struct node *n = head;
    struct node *first = head;
    struct node *previous = NULL;
    struct node *temp;

    while (n->next != NULL) { // move last to head
        previous = n;
        n = n->next;
    }
    n->next = first;
    previous->next = NULL;
    head = n;
    temp = n;
    while (1) { // loop until first is last where it will break
        while (n->next != NULL) {
            previous = n;
            n = n->next;
        }
        if (n == first) {
            break;
        } else {
            n->next = first; // move the last the between the head and the first, but after the previously moved element
            temp->next = n; 
            temp = n;
            previous->next = NULL;
            n = head;
        }
    }
    n->next = NULL;
    /* efficient method
    if (head == NULL) {
    	return head;
    }
    // only one thing in list, return same
    if (head->next == NULL) {
    	return head;
    }
    // more than one, reversing the linked list 
    struct node *n = head;
    struct node *next = NULL;
    struct node *previous = NULL;
	while (n != NULL) {
        next  = n->next; // store n->next in next
        n->next = previous; // assign n->next, first time n->next will be NULL as previous is initially NULL, second time n->next will be the head as previous is head 
        previous = n; // first time previous will be head, then the second element and so on
        n = next; // move forwards to reverse the next node
    }
    head = previous;
    */
	return head;
}

// print contents of list in Python syntax

void print_list(struct node *head) {
    printf("[");
    for (struct node *n = head; n != NULL; n = n->next) {
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

// return pointer to last node in list
// NULL is returned if list is empty

struct node *last(struct node *head) {
    if (head == NULL) {
        return NULL;
    }

    struct node *n = head;
    while (n->next != NULL) {
        n = n->next;
    }
    return n;
}

// create a new list node containing value
// and append it to end of list

struct node *append(struct node *head, int value) {
    // new node will be last in list, so next field is NULL
    struct node *n =  create_node(value, NULL);
    if (head == NULL) {
        // new node is now  head of the list
        return n;
    } else {
        // change next field of last list node
        // from NULL to new node
        last(head)->next = n;  /* append node to list */
        return head;
    }
}

// Create a new struct node containing the specified data,
// and next fields, return a pointer to the new struct node.

struct node *create_node(int data, struct node *next) {
    struct node *n;

    n = malloc(sizeof (struct node));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = data;
    n->next = next;
    return n;
}
