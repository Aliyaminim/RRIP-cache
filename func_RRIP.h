/* A header file to a C program which shows implementation of 
   Static Re-Reference Interval Prediction(RRIP) in High Perfomance Cache Replacement */

#pragma once

/* A List Node (the RRIP chain is implemented using Doubly Linked List) */
typedef struct node_t {
    struct node_t *next, *prev;
    long data;                  //the data stored in this Node
    unsigned value;             //the RRIP value stored by a 2-bit register per Node (details below)
} Node_t;
/* An RRPV of 0 implies that a cache block is predicted to be re-referenced
   in the near-immediate future while RRPV of 3 implies that a cache 
   block is predicted to be re-referenced in the distant future. 
   An RRPV of 2 represents a long re-reference interval. 
   Quantitavely, RRIP predicts that blocks with small RRPVs are re-referenced sooner 
   than blocks with large RRPVs */


/* A List (a collection of Nodes in ascending order according to their RRIP) */
typedef struct list_t {
    Node_t *head, *fst_dist, *tail;
    /* head is a pointer to the head of the List
       fst_dist is a pointer to the first Node in the List with distant RRIP
       tail is a pointer to the tail of the List */
    long size;                  //total number of Nodes in List
    long full_nodes;            //number of filled Nodes in List
} List_t;

/* A Hash table element structure, which contains long integer data (could be page number) 
   and Node_t chain pointer value */
typedef struct HtElem {
    long data;
    Node_t *value;
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
List_t *create_list(const long size);

/* A function to delete a Node from List */
void dequeue(Node_t * node, List_t * list, HashTable * table);

/* A function to add a Node with given 'data' to both List and Hash using RRIP, if 
   it hasn't been in List before */
void enqueue(List_t * list, HashTable * table, const long data);

/* A function to re-link cache blocks, if current Node has already been in List */
void cache_hit(Node_t * node, List_t * list);

/* A function to perform cache replacement using RRIP*/
int replacement_RRIP(long page, List_t * list, HashTable * table);

/* A function to delete a Node from List */
void dequeue_cop(Node_t * node, List_t * list, Node_t ** hash);

/* A function to add a Node with given 'data' to both List and Hash using RRIP, if 
   it hasn't been in List before */
void enqueue_cop(List_t * list, Node_t ** hash, const long data);
//definition of hash can be changed

/* A function to perform cache replacement using RRIP*/
int replacement_RRIP_cop(const long page, List_t * list, Node_t ** hash);

/* A utility function to print List */
void print_list(const List_t * list);

/* A utility function to delete List */
void delete_list(List_t * list);

/* A function to realloc hash_RRIP and hash_LRU, when new page doesn't fit into them*/
void update_hash(long *phashsize, const long page, Node_t ** hash_RRIP,
                 QNode ** hash_LRU);

/* A utility function to free hash_RRIP */
void delete_hashRRIP(Node_t ** hash_RRIP);
