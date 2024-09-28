#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>


void SelectionSort(int* array, int array_size) {
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    for (int i = 0; i <= array_size - 2; i++) {
        int min_element_index = i;
        for (int j = i + 1; j <= array_size - 1; j++) {
            if (array[j] > array[min_element_index]) {
                min_element_index = j;
            }
        }
        int min = array[min_element_index];
        array[min_element_index] = array[i];
        array[i] = min;
    }
    gettimeofday(&stop, NULL);
    printf("took %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
}
