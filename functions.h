#pragma once

typedef struct node_t {
        struct node_t *next, *prev;
        long data;
	unsigned value;
} Node_t;

typedef struct list_t {
        Node_t *head, *fst_dist, *tail;
	long size;
        long full_nodes; //how many are nodes in list? to compare with cache size
} List_t;

List_t* create_list(long size);

Node_t* newNode(long data);

int isListEmpty(List_t* list);

int isListFull(List_t* list);

void dequeue(Node_t* node, List_t* list, Node_t ** hash);

void enqueue(List_t* list, Node_t ** hash, long data);
//definition of hash can be changed

void print_list(List_t* list);

void delete_list(List_t* list);

//Node_t* append(Node_t* bottom, int a);