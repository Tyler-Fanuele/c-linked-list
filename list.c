/*
    Copyright 2022, Tyler Fanuele
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/*
    Node Implmentation
*/

Node* node_init_default( void ) {
    Node* tempNode = (Node*)malloc(sizeof(Node));
    if (!tempNode) {
        printf("Node init default failed to malloc\n");
        exit(1);
    }
    tempNode->data = 0;
    tempNode->next = NULL;
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

/*
    List Implmentation
*/

List* list_init_default( void ) {
    List* tempList = (List*)malloc(sizeof(List));
    if(!tempList) {
        printf("List init node default failed to malloc\n");
        exit(1);
    }
    tempList->head = node_init_default();
    return tempList;
}
List* list_init(int data) {
    List* tempList = (List*)malloc(sizeof(List));
    if (!tempList) {
        printf("List init failed to malloc\n");
        exit(1);
    }
    tempList->head = node_init(data);
    return tempList;
}
List* list_init_node(Node* pnode) {
    List* tempList = (List*)malloc(sizeof(List));
    if (!tempList) {
        printf("List Init failed to malloc\n");
        exit(1);
    }
    tempList->head = pnode;
    return tempList;
}
void list_destroy(List** phlist) {
    Node* temp = (*phlist)->head;
    Node* next;
    while(temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*phlist);
    *phlist = NULL;
}
void list_push(List** plist, int data) {
    Node* temp = (*plist)->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node_init(data);
}
