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

Node* node_init_default( void );
Node* node_init(int data);
void node_destroy(Node** phnode);

List* list_init_default( void );
List* list_init_node(Node* pnode);
List* list_init(int data);
void list_push(List** plist, int data);
void list_destroy(List** phlist);

#endif // LIST_H
