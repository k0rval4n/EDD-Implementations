#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "insertion.h"
#include "merge_sort.h"


int main() {
    int array_size;
    printf("Number of elements of array: ");
    scanf("%d", &array_size);
    int* array = calloc(array_size, sizeof(int));
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    int* merged_array = MergeSort(array, array_size);
    gettimeofday(&stop, NULL);
    printf("\ntook %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
    for (int i = 0; i < array_size ; i++) {
        printf("%d, ", merged_array[i]);
    }
    free(array);
    free(merged_array);
    return 0;
}
