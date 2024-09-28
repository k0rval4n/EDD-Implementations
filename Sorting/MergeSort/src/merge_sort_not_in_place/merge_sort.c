#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "merge.h"


int* MergeSort(int* array, int array_size) {
    if (array_size == 1) {
        return array;
    }
    int first_part_size = (int)floor((array_size) / 2);
    int second_part_size = array_size - first_part_size;
    int* sorted_first_part = MergeSort(array, first_part_size);
    int* sorted_second_part = MergeSort(array + first_part_size, second_part_size);
    return Merge(sorted_first_part, first_part_size, sorted_second_part, second_part_size);
}
