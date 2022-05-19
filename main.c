/*
    Copyright 2022, Tyler Fanuele
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[]) {
    List* test = list_init(200);
    list_append(&test, 4);
    list_append(&test, 4);
    list_append(&test, 5);
    list_push(&test, 100);
    list_print_debug(&test);
    printf("front %d, back %d\n", list_peak_front(&test), list_peak_back(&test));
    list_destroy(&test);
    return 0;
}
