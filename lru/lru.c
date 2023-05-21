/* A C program which includes functions to perform LRU cache replacement 
   using queue and hashing. 
   This program is essential for comparing the efficiency of the RRIP replacement 
   with the LRU cache replacement. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lru.h"
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

int lru(long page, Queue * queue, QNode ** hash)
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

void delete_hashLRU(QNode** hash_LRU)
{
	QNode* next;
	QNode* top = hash_LRU[0];

	while (top != NULL) {
		next = top->next;
		free(top);
		top = next;
	}
}

void delete_queue(Queue * queue)
{
	QNode *next;
	QNode *top = queue->top;

	while (top != NULL) {
		next = top->next;
		free(top);
		top = next;
	}

	free(queue);
}



