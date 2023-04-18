#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

List_t* create_list(long size)
{
        List_t* list = calloc(1, sizeof(List_t));
        list->head = list->fst_dist = NULL;
        list->size = size;
        list->full_nodes = 0;

        assert(list != NULL && "Heap overflow!");

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

void enqueue(List_t* list, Node_t ** hash, long data)
{
        //in progress... 
}

int isListFull(List_t* list)
{
    return list->size == list->full_nodes;
}

int isListEmpty(List_t* list)
{
        if ((list->head == NULL) && (list->full_nodes == 0))
                return 1;
        else
                return 0;
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

/*Node_t* append(Node_t* bottom, long a)
{
	Node_t* elem = calloc(1, sizeof(Node_t));
	elem->next = NULL;
        elem->prev = bottom;
	elem->data = a;

	if (bottom != NULL)
		bottom->next = elem;
	
	return elem;
}*/
