#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


int* SelectionSort(int* array, int array_size) {
    int* sorted_array = calloc(array_size, sizeof(int));
    int elements_moved = 0;
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    while (elements_moved < array_size) {
        int min_element_index = 0;
        for (int i = 0; i < array_size; i++) {
            if (array[i] != 2147483647) {
                if (array[i] < array[min_element_index]) {
                    min_element_index = i;
                }
            }
        }
        sorted_array[array_size - 1 - elements_moved] = array[min_element_index];
        array[min_element_index] = 2147483647;
        elements_moved++;
    }
    gettimeofday(&stop, NULL);
    printf("\ntook %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
    return sorted_array;
}
