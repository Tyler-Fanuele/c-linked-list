/*
    Copyright 2022, Tyler Fanuele
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[]) {
    List* test = list_init(200);

    list_append(test, 4);
    list_append(test, 4);
    list_append(test, 5);
    list_push(test, 100);

    printf("front %d, back %d\n", list_peak_front(test), list_peak_back(test));

    List* test2 = list_reverse_copy(test);
    
    list_append(test2, 3);

    list_print_debug(test);
    list_print_debug(test2);

    list_destroy(&test2);
    list_destroy(&test);
    return 0;
}
