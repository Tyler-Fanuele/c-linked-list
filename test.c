/*
    Copyright 2022, Tyler Fanuele
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

enum passVal {
    skip = -1,
    fail = 0,
    pass = 1
};

enum passVal createTest() {
    List* testList = list_init_default();
    if (testList->head->data != 0) {
        printf("");
        list_destroy(&testList);
        return fail;
    }
}

int main(int argc, char* argv[]) {
    
    return 0;
}
