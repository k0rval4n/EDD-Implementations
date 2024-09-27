#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int* InsertionSort(int* array, int array_size){
    int* sorted_array = calloc(array_size, sizeof(int));
    int sorted_array_actual_size = 0;
    for (int i = 0; i < array_size; i++) {
        int element = array[i];
        bool inserted = false;
        for (int j = 0; j < sorted_array_actual_size; j++) {
            if (element < sorted_array[j]) {
                for (int k = sorted_array_actual_size; k > j; k--) {
                    sorted_array[k] = sorted_array[k - 1];
                }
                sorted_array[j] = element;
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            sorted_array[sorted_array_actual_size] = element;
        }
        sorted_array_actual_size++;
    }
    return sorted_array;
}
