#ifndef LIST_H
#define LIST_H
typedef struct node Node;
struct node {
    int data;
    Node* next;
};


struct list {
    Node* head;
};
typedef struct list List;

/*
    Node def
*/

Node* node_init_default( void );
Node* node_init(int data);
void node_destroy(Node** phnode);

/*
    List def
*/


// list init
List* list_init_default( void );
List* list_init_node(Node* pnode);
List* list_init(int data);

// appending list
void list_append(List** phlist, int data);
void list_push(List** phlist, int data);

// list access
int list_peak_front(List** phlist);
int list_peak_back(List** phlist);

// list destructor
void list_destroy(List** phlist);

// list other
void list_print_debug(List** phlist);

#endif // LIST_H
