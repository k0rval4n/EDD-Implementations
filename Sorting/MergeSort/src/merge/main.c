#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "insertion.h"
#include "merge.h"


int main() {
    int array1_size;
    printf("Number of elements of first array: ");
    scanf("%d", &array1_size);
    int* array1 = calloc(array1_size, sizeof(int));
    for (int i = 0; i < array1_size; i++) {
        scanf("%d", &array1[i]);
    }
    InsertionSort(array1, array1_size);
    int array2_size;
    printf("Number of elements of second array: ");
    scanf("%d", &array2_size);
    int* array2 = calloc(array2_size, sizeof(int));
    for (int i = 0; i < array2_size; i++) {
        scanf("%d", &array2[i]);
    }
    InsertionSort(array2, array2_size);
    int* merged_array = Merge(array1, array1_size, array2, array2_size);
    for (int i = 0; i < (array1_size + array2_size); i++) {
        printf("%d, ", merged_array[i]);
    }
    free(array1);
    free(array2);
    free(merged_array);
    return 0;
}
