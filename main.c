/*
    Copyright 2022, Tyler Fanuele
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[]) {
    List* test = list_init(200);
    list_push(&test, 4);
    list_push(&test, 4);
    list_push(&test, 4);
    list_destroy(&test);
    return 0;
}
