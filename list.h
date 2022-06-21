#ifndef LIST_H
#define LIST_H
#include "node.h"


struct list {
    Node* head;
};
typedef struct list List;



/*
    List def
*/


// list init

/*
    Creates a list with a default node. a node with null for next and a 0 for data
*/
List* list_init_default( void );
/*
    Creates a list with the given node
*/
List* list_init_node(Node* pnode);
/*
    Creates a list with a node with the given data int
*/
List* list_init(int data);

// appending list

/*
    Adds a node to the beginnig of the list
    with the given data int
*/
void list_append(List* plist, int data);
/*
    Adds a node to the end of the list
    with the given data int
*/
void list_push(List* plist, int data);

// list access

/*
    Returns the integer at the beginning of the list
*/
int list_peak_front(List* plist);
/*
    Returns the integer at the end of the list
*/
int list_peak_back(List* plist);

// list destructor

/*
    Frees the entire list
*/
void list_destroy(List** phlist);

// list other

/*
    the list is deep coppied and returned 
*/
List* list_copy(List* plist);

/*
    The input list is reversed
*/
void list_reverse(List* plist);

/*
    The list is deep copied and reversed;
*/
List* list_reverse_copy(List* plist);

/*
    Prints the entire list in a debug format
*/
void list_print_debug(List* plist);

#endif // LIST_H
