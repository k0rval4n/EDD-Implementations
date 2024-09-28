#pragma once


typedef struct to_free_node {
    int* merged_array_to_free;
    struct to_free_node* next_node;
} ToFreeNode;

typedef struct to_free_list {
    ToFreeNode* head;
    ToFreeNode* tail;
} ToFreeList;