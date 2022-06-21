/*
    Copyright 2022, Tyler Fanuele
*/

#include "list.h"
#include <stdlib.h>
#include <stdio.h>



/*
    List Implmentation
*/

List* list_init_default( void ) {
    List* tempList = (List*)malloc(sizeof(List));
    if(!tempList) {
        printf("List init node default failed to malloc\n");
        exit(1);
    }
    tempList->head = NULL;
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
void list_append(List* plist, int data) {
    if (!plist->head) {
        plist->head = node_init(data);
        return;
    }
    Node* temp = plist->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node_init(data);
}

void list_push(List* plist, int data) {
    if (!plist->head) {
        plist->head = node_init(data);
    }
    Node* temp = plist->head;
    Node* new =  node_init(data);
    new->next = temp;
    temp = new;
    plist->head = temp;
}

void list_print_debug(List* plist) {
    Node* temp = plist->head;
    int i = 0;
    printf("Linked list {\n");
    while(temp->next != NULL) {
        printf("Node[%d] -> %d\n", i, temp->data);
        temp = temp->next;
        i++;
    }
    printf("Node[%d] -> %d\n", i, temp->data);
    printf("}\n");
}

int list_peak_front(List* plist) {
    if (!plist->head) {
        printf("list peak front null node");
        exit(1);
    }
    return plist->head->data;
}

int list_peak_back(List* plist) {
    Node* temp = plist->head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    return temp->data;
}

void list_reverse(List* plist) {
    Node* prev = NULL;
    Node* curr = plist->head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    plist->head = prev;
}

List* list_copy(List* plist) {
    List* retList = list_init_default();
    Node* curr = plist->head;
    while (curr->next) {
        list_append(retList, curr->data);
        curr = curr->next;
    }
    list_append(retList, curr->data);
    return retList;
}

List* list_reverse_copy(List* plist) {
    List* retList = list_copy(plist);
    list_reverse(retList);
    return retList;
}
