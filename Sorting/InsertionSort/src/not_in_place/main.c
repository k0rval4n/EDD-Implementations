#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertion.h"


int main() {
    int array_size;
    scanf("%d", &array_size);
    int* array = calloc(array_size, sizeof(int));
    for (int i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }
    int* sorted_array = InsertionSort(array, array_size);
    for (int i = 0; i < array_size; i++) {
        printf("%d, ", sorted_array[i]);
    }
    free(array);
    free(sorted_array);
    return 0;
}
