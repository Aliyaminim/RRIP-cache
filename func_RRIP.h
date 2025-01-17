/* A header file to a C program which shows implementation of 
   Static Re-Reference Interval Prediction(RRIP) in High Perfomance Cache Replacement */

#pragma once

/* A List Node (the RRIP chain is implemented using Doubly Linked List) */
struct node_t;


/* A List (a collection of Nodes in ascending order according to their RRIP) */
struct list_t;

/* A Hash table element structure, which contains long integer data (could be page number) 
   and Node_t chain pointer value */
typedef struct HtElem {
    long data;
    struct node_t *value;
} HtElem;

/* A Node Hash table Linked list, contains hash table element pointer of element and 
   Node Hash table Linked list pointer to next element */
typedef struct NodeHtLl {
    HtElem *elem;
    struct NodeHtLl *next;
} NodeHtLl;

/* A Hash table, contains the pointer to array of HtElem pointers and pointer to 
   array of Node Hash table Linked list pointers */
typedef struct HashTable {
    HtElem **elems;
    NodeHtLl **overflow_list;
} HashTable;

/* A utility function to create an empty List.
   The list can have at most 'size' nodes */
struct list_t *create_list(const long size);

/* A function to delete a Node from List */
void dequeue(struct node_t * node, struct list_t * list, HashTable * table);

/* A function to add a Node with given 'data' to both List and Hash using RRIP, if 
   it hasn't been in List before */
void enqueue(struct list_t * list, HashTable * table, const long data);

/* A function to re-link cache blocks, if current Node has already been in List */
void cache_hit(struct node_t * node, struct list_t * list);

/* A function to perform cache replacement using RRIP */
int replacement_RRIP(long page, struct list_t * list, HashTable * table);

/* A function to perform cache replacement using RRIP and simple hash */
int replacement_RRIP_cop(long page, struct list_t * list, struct node_t ** hash);

/* A utility function to print List */
void print_list(const struct list_t * list);

void print_results(const long count_RRIP, const long count_check, const long count_LRU);

/* A utility function to free hash_RRIP */
void delete_hashRRIP(struct node_t ** hash_RRIP);

/* A utility function to delete List */
void delete_list(struct list_t * list);

/* A function to realloc hash_RRIP and hash_LRU, when new page doesn't fit into them*/
void update_hash(long *phashsize, const long page, struct node_t ** hash_RRIP,
                 struct QNode ** hash_LRU);


