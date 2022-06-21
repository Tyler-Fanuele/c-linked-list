#include "node.h"
#include <stdlib.h>
#include <stdio.h>
/*
    Node Implmentation
*/

Node* node_init_default( void ) {
    Node* tempNode = NULL;
    return tempNode;
}
Node* node_init(int data) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    if (!tempNode) {
        printf("Node init failed to malloc\n");
        exit(1);
    }
    tempNode->data = data;
    tempNode->next = NULL;
    return tempNode;
}
void node_destroy(Node** phnode) {
    free(*phnode);
    *phnode = NULL;
}
