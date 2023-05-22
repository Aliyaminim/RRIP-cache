/* A Header file to a C program which includes functions to perform LRU cache replacement 
   using queue and hashing. */

#pragma once

typedef struct QNode {
    long page;
    struct QNode *prev, *next;
} QNode;

typedef struct Queue {
    QNode *top, *end;
    long max_cell;
    long full_cell;
} Queue;

Queue *createQueue(const long m);

void add_qnode(Queue * queue, const long page, QNode ** hash);

int del_qnode(Queue * queue, QNode ** hash);

int lru(const long page, Queue * queue, QNode ** hash);

void delete_hashLRU(QNode ** hash_LRU);

void delete_queue(Queue * queue);
