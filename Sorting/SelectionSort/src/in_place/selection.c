#include <stdlib.h>
#include <stdio.h>


void SelectionSort(int* array, int array_size) {
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
}
