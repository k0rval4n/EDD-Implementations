#include <stdlib.h>
#include <stdio.h>


int* Merge(int* array1, int array1_size, int* array2, int array2_size) {
    // TODO: free this allocation:
    int* merged_array = calloc((array1_size + array2_size), sizeof(int));
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
