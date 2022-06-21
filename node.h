#ifndef NODE_H
#define NODE_H
typedef struct node Node;
struct node {
    int data;
    Node* next;
};

/*
    Node def
*/

Node* node_init_default( void );
Node* node_init(int data);
void node_destroy(Node** phnode);

#endif //NODE_H
