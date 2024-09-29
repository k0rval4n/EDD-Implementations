#include <stdlib.h>
#include <stdio.h>
#include "merge.h"
#include "to_free_list.h"


int* Merge(int* array1, int array1_size, int* array2, int array2_size, ToFreeList* to_free_list) {
    int* merged_array = calloc((array1_size + array2_size), sizeof(int));
    ToFreeNode* to_free_node = calloc(1, sizeof(ToFreeNode));
    to_free_node->merged_array_to_free = merged_array;
    if (to_free_list->head == NULL) {
        to_free_list->head = to_free_node;
        to_free_list->tail = to_free_node;
    } else {
        to_free_list->tail->next_node = to_free_node;
        to_free_list->tail = to_free_node;
    }
    int array1_elements_moved = 0;
    int array2_elements_moved = 0;
    while ((array1_elements_moved + array2_elements_moved) < (array1_size + array2_size)) {
        if ((array1_elements_moved < array1_size) && (array2_elements_moved) < (array2_size)) {
            if (array1[array1_elements_moved] <= array2[array2_elements_moved]) {
                merged_array[array1_elements_moved + array2_elements_moved] = array1[array1_elements_moved];
                array1_elements_moved++;
            } else {
                merged_array[array1_elements_moved + array2_elements_moved] = array2[array2_elements_moved];
                array2_elements_moved++;
            }
        } else if (array1_elements_moved == array1_size) {
            merged_array[array1_elements_moved + array2_elements_moved] = array2[array2_elements_moved];
            array2_elements_moved++;
        } else {
            merged_array[array1_elements_moved + array2_elements_moved] = array1[array1_elements_moved];
            array1_elements_moved++;
        }
    }
    return merged_array;
}
