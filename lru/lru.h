/* A Header file to a C program which includes functions to perform LRU cache replacement 
   using queue and hashing. */

#pragma once

/* A Queue Node (the LRU chain is implemented using Doubly Linked List) */
struct QNode;

/* A Cache Queue (a collection of Nodes) */
struct Queue;

/* A utility function to create an empty Queue */
struct Queue *createQueue(const long m);

/* A function to add a Node with given 'data' to both Queue and Hash, 
   if it hasn't been in Queue before */
void add_qnode(struct Queue * queue, const long page, struct QNode ** hash);

/* A function to delete a Node from Queue */
int del_qnode(struct Queue * queue, struct QNode ** hash);

/* A function to perform cache replacement using LRU */
int lru(const long page, struct Queue * queue, struct QNode ** hash);

/* A utility function to free hash_LRU */
void delete_hashLRU(struct QNode ** hash_LRU);

/* A utility function to delete Queue */
void delete_queue(struct Queue * queue);
