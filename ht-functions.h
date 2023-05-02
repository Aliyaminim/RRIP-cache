#pragma once

int modular = 10007;

struct node_t {
    //todo
};

//simple hash table in terms of array with linked list head in each element
//
//P.S. I understand that it is not the best hash table implementation, but it is what it is
struct hash_table {
    struct node_ht *arr[modular] = { NULL };

};

//todo __HT_LINKED_LIST_HEAD__ 

