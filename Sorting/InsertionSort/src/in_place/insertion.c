#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/time.h>


void InsertionSort(int* array, int array_size) {
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    for (int i = 1; i <= array_size - 1; i++) {
        int j = i;
        while ((j > 0) && (array[j] < array[j - 1])) {
            int array_j = array[j];
            array[j] = array[j - 1];
            array[j - 1] = array_j;
            j--;
        }
    }
    gettimeofday(&stop, NULL);
    printf("\ntook %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
}
