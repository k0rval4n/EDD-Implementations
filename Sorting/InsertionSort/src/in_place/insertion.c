#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void InsertionSort(int* array, int array_size) {
    for (int i = 1; i <= array_size - 1; i++) {
        int j = i;
        while ((j > 0) && (array[j] < array[j - 1])) {
            int array_j = array[j];
            array[j] = array[j - 1];
            array[j - 1] = array_j;
            j--;
        }
    }
}
