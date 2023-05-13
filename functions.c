#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

List_t* create_list(long size)
{
        List_t* list = calloc(1, sizeof(List_t));
        assert(list != NULL && "Heap overflow!");
        Node_t* cur = NULL;
        Node_t* prev = NULL;

        list->fst_dist = NULL;
        list->head = newNode(0);
        cur = list->head;
        
        for (int i = 0; i < size - 1; ++i)
        {
                prev = cur;
                cur = newNode(0);
                cur->prev = prev;
                prev->next = cur;
        }

        list->tail = cur;
        list->size = size;
        list->full_nodes = 0;

        return list;
}

Node_t* newNode(long data) 
{
        Node_t* res = calloc(1, sizeof(Node_t));
        res->next = res->prev = NULL;
        res->data = data;
        res->value = 2;
        
        return res;
}

int isListFull(List_t* list)
{
    return list->size == list->full_nodes;
}

int isListEmpty(List_t* list)
{
        return list->tail == NULL;
}


void dequeue(Node_t* node, List_t* list, Node_t ** hash) 
{
        list->fst_dist = node->next;

        if (node != list->head) 
                node->prev->next = node->next;
        else 
                list->head = node->next;

        if (node != list->tail)
                node->next->prev = node->prev;
        else 
                list->tail = node->prev;
        
        
        list->full_nodes--;
        hash[node->data] = NULL;
        free(node);
}

void enqueue(List_t* list, Node_t ** hash, long data)
{
        Node_t* curnode = newNode(data);

        if (isListFull(list)) {
                if (list->fst_dist == NULL) {
                        int i = 3 - list->tail->value; 
                        Node_t* tmp = list->head;
                        int state = 0;
                        
                        for (;tmp != NULL;) {
                                tmp->value += i;
                                if ((tmp->value == 3) && (state == 0)) {
                                        list->fst_dist = tmp;
                                        state = 1;
                                }
                                tmp = tmp->next;
                        }
                }

                Node_t* hlp = list->fst_dist->prev;
                dequeue(list->fst_dist, list, hash);
                
                if (hlp != NULL) {
                        if (hlp != list->tail)
                                hlp->next->prev = curnode;
                        else 
                                list->tail = curnode;
                        hlp->next = curnode;   
                } else {
                        list->head->prev = curnode;
                        list->head = curnode;
                }

                curnode->next = list->fst_dist;
                curnode->prev = hlp;

                list->full_nodes++;
                hash[data] = curnode;
        } else {
                if (isListEmpty(list)) {
                        list->head = curnode;
                } else {
                        list->tail->next = curnode;
                        curnode->prev = list->tail;
                }
                list->tail = curnode;
                list->full_nodes++;
                hash[data] = curnode;
        }

}

void print_list(List_t* list)
{
        Node_t* head = list->head;

        while (head != NULL)
        {
                printf("%ld ", head->data);
                head = head->next;
        }

        printf("\n");
        return;
}

void delete_list(List_t* list)
{
        Node_t* next;
        Node_t* top = list->head;

	while (top != NULL)
	{
		next = top->next;
		free(top);
		top = next;
	}

        free(list);
}

Node_t* append(Node_t* bottom, long a)
{
	Node_t* elem = calloc(1, sizeof(Node_t));
	elem->next = NULL;
        elem->prev = bottom;
	elem->data = a;

	if (bottom != NULL)
		bottom->next = elem;
	
	return elem;
}
