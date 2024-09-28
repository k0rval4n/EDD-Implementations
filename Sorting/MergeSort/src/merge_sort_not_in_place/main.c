#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include "insertion.h"
#include "merge_sort.h"
#include "to_free_list.h"


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
    ToFreeList to_free_list = {
        .head = NULL,
        .tail = NULL
    };
    int* merged_array = MergeSort(array, array_size, &to_free_list);
    gettimeofday(&stop, NULL);
    printf("\ntook %lf seconds\n", ((stop.tv_sec - start.tv_sec) * 1000000.0 + stop.tv_usec - start.tv_usec) / 1000000.0);
    for (int i = 0; i < array_size ; i++) {
        printf("%d, ", merged_array[i]);
    }
    free(array);
    ToFreeNode* actual_node = to_free_list.head;
    while (actual_node != NULL)
    {
        ToFreeNode* next_node = actual_node->next_node;
        free(actual_node->merged_array_to_free);
        free(actual_node);
        actual_node = next_node;
    }
    return 0;
}
