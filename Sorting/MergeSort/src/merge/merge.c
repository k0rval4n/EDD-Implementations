#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


int* Merge(int* array1, int array1_size, int* array2, int array2_size) {
    int* merged_array = calloc((array1_size + array2_size), sizeof(int));
    int array1_elements_moved = 0;
    int array2_elements_moved = 0;
    struct timeval stop, start;
    gettimeofday(&start, NULL);
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
    gettimeofday(&stop, NULL);
    printf("\ntook %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
    return merged_array;
}
