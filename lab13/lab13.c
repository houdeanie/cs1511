// write functions for a program to do stuff
// Dean Hou and Isheeta Sinha
// z5163159 and z5164929
// week 13 lab
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    struct node *next;
    int       data;
};

int count(int value, struct node *list);
struct node *get_nth(int n, struct node *head);
struct node *insert_nth(int n, struct node *new_node, struct node *head);
struct node *delete_nth(int n, struct node *head);
struct node *delete_odd(struct node *head);

void print_list(struct node *head);
struct node *reverse(struct node *list);
struct node *create_node(int data, struct node *next);
struct node *last(struct node *head);
struct node *append(struct node *head, int value);
void free_list(struct node *head);

#define MAX_LINE 4096

// simple main function to test count, get_nth, insert_nth, delete_nth, delete_odd

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
            // free memory even though program is exiting
            // so we can check for memory not freed by other functions
            // by running dcc --leak-check
            free_list(list_head);
            return 0;
        }

        int i = 0;
        while (isalpha(line[i]) || line[i] == '_') {
            i++;
        }
        int argument = atoi(&line[i]);
        line[i] = '\0';

        if (strcmp(line, "append") == 0) {
            list_head = append(list_head, argument);
        } else if (strcmp(line, "count") == 0) {
            printf("count(%d) returns %d\n", argument, count(argument, list_head));
        } else if (strcmp(line, "get_nth") == 0) {
            struct node *n = get_nth(argument, list_head);
            if (n == NULL) {
                printf("get_nth(%d) returned NULL\n", argument);
            } else {
                printf("get_nth(%d) returned a pointer to a node containing %d\n", argument, n->data);
            }
        } else if (strcmp(line, "delete_nth") == 0) {
            list_head = delete_nth(argument, list_head);
        } else if (strcmp(line, "insert_nth") == 0) {
            // insert a node containing 42
            struct node *new_node = create_node(42, NULL);
            list_head = insert_nth(argument, new_node, list_head);
        } else if (strcmp(line, "delete_odd") == 0) {
            list_head = delete_odd(list_head);
        } else if (strcmp(line, "") != 0) {
            printf("Unknown command: '%s'\n", line);
        }
    }
}

// Return number of nodes in the list containing value.

int count(int value, struct node *head) {
    struct node *curr = head;
    int count = 0;
    while (curr != NULL) {
    	if (curr->data == value) {
    		count++;
    	}
    	curr = curr->next;
    }
    free(curr);
    return count;
}

// Return a pointer to the node in  position n in the list.
// Position 0 is the first node in the list.
// Return NULL if the list has no n-th node.

struct node *get_nth(int n, struct node *head) {
    struct node *curr = head;
    int count = 0;
    while (curr != NULL) {
    	if (count == n) {
    		return curr;
    	}
    	count++;
    	curr = curr->next;
    }
    return NULL;
}

// Delete the node in  position  n in the list.
// The deleted nodes is freed.
// The first node in the list is in position 0.
// Do nothing if there is no position n in the list.
// The head of the list is returned.

struct node *delete_nth(int n, struct node *head) {
	if (head == NULL) {
        return NULL;
    }
    struct node *curr = head;
    struct node *prev = head;
    int count = 0;
    if (count == n) { // if first one
        head = head->next;
        curr->next = NULL;
        free(curr);
        return head;
    }
    while (curr != NULL) {
        if (count == n) {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    free(curr);
    return head;
}


// Delete all nodes in the list containing odd numbers.
// Any deleted nodes are freed.
// The head of the list is returned.

struct node *delete_odd(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *curr = head;
    while (curr != NULL) {
        if (curr->data % 2 != 0) {
            head = curr->next;
            free(curr);
            curr = head;
        } else {
            break;
        }
    }
    struct node *prev = head;
    while (curr != NULL) {
        if (curr->data % 2 != 0) {
        	prev->next = curr->next;
        	free(curr);
        	curr = prev;
        }
        prev = curr;
       	curr = curr->next;
    }
    free(curr);
    return head;
}

// Insert new_node before position n in the list.
// The first node in the list is in position 0.
// If n == length of the list, new_node is appended to list.
// Otherwise do nothing if there is no position n in the list.
// The head of the list is returned.

struct node *insert_nth(int n, struct node *new_node, struct node *head) {
    struct node *curr = head;
    struct node *prev = NULL;
    int count = 0;
    if (count == n) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    while (curr != NULL) {
        if (count == n) {
            prev->next = new_node;
            new_node->next = curr;
            return head;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL && count == n) {
        prev->next = new_node;
        new_node->next = curr;
    }
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
    if (head == NULL || head->next == NULL) {
        return head;
    }
    return last(head->next);
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

void free_list(struct node *head) {
    if (head != NULL) {
        free_list(head->next);
        free(head);
    }
}

