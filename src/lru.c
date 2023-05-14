/* A C program which shows implementation of LRU cache using queue and hashing. 
   This program is essential for comparing the efficiency of the RRIP with 
   the LRU cache replacement. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct QNode {
    long page;
    struct QNode *prev, *next;
} QNode;

typedef struct Queue {
    QNode *top, *end;
    long max_cell;
    long full_cell;
} Queue;


Queue *createQueue(long m)
{
    Queue *queue = (Queue *) calloc(1, sizeof(Queue));
    queue->max_cell = m;
    queue->full_cell = 0;
    queue->top = queue->end = NULL;
    return queue;
}

int isQueueEmpty(Queue * queue)
{
    return queue->end == NULL;
}

void add_qnode(Queue * queue, long page, QNode ** hash)
{
    QNode *tmp = (QNode *) calloc(1, sizeof(QNode));
    assert(queue->full_cell <= queue->max_cell);
    tmp->page = page;
    tmp->prev = NULL;
    tmp->next = queue->top;
    if (queue->top != NULL)
        queue->top->prev = tmp;
    else {
        queue->end = tmp;
    }
    queue->top = tmp;
    queue->full_cell += 1;
    hash[page] = tmp;
}


int isQueueFull(Queue * queue)
{
    return queue->max_cell == queue->full_cell;
}

int del_qnode(Queue * queue, QNode ** hash)
{
    QNode *tmp = queue->end;
    hash[queue->end->page] = NULL;
    if (queue->full_cell == 1) {
        QNode *tmp = queue->end;
        queue->top = queue->end = NULL;
    } else {
        queue->end = queue->end->prev;
        queue->end->next = NULL;
    }
   
    queue->full_cell -= 1;
    free(tmp);
    return 0;
}

int lru(Queue * queue, long page, QNode ** hash)
{
    QNode *tmp = hash[page];
    if (isQueueEmpty(queue)) {
        add_qnode(queue, page, hash);
        return 0;
    }

    if (tmp == NULL) {
        if (isQueueFull(queue)) {
            del_qnode(queue, hash);
        }
        add_qnode(queue, page, hash);
        return 0;
    } else {
        if ((queue->full_cell == 1) || (tmp == queue->top)) {
            return 1;
        }
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
        else
            queue->end = tmp->prev;

        assert(tmp == hash[page]);  
        hash[page] = NULL;
        free(tmp);
        queue->full_cell -= 1;

        add_qnode(queue, page, hash);
        return 1;
    }
}

int main()
{
    QNode **hash;
    long m, n, page, kol, cashe_hit = 0;
    Queue *queue;

    scanf("%ld", &m); //m is a cache size
    scanf("%ld", &n); //n is a number of requests

    hash = calloc(n + 1, sizeof(QNode *));
    assert(hash != NULL);
    kol = n + 1; //kol is a current hash size 

    if (m == 0) {
        printf("%s\n", "The cache size must be greater than zero.");
        return 0;
    }
    queue = createQueue(m);

    for (long i = 0; i < n; i++) {
        scanf("%ld", &page);
        if (kol - 1 < page) {
            //if the hash size isn't enough to store a new page, it needs to be resized.
            hash = (QNode **) realloc(hash, (page + 1) * sizeof(QNode *));
            assert(hash != NULL);
            for (long i = kol; i <= page; i++)
                hash[i] = NULL;
            kol = page + 1;
        }

        cashe_hit += lru(queue, page, hash);
    }

    printf("%ld\n", cashe_hit); //prints overall number of cache hits during whole process
    return 0;
}