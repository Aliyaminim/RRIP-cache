#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

struct node_t* append(struct node_t* bottom, int a)
{
	struct node_t* elem = calloc(1, sizeof(struct node_t));
	elem->next = NULL;
        elem->prev = bottom;
	elem->data = a;

	if (bottom != NULL)
		bottom->next = elem;
	
	return elem;
}

struct list_t* create_list()
{
        struct list_t* list = calloc(1, sizeof(struct list_t));
        list->head = calloc(1, sizeof(struct node_t));

        assert(list != NULL && "Heap overflow!");
        assert(list->head != NULL && "Heap overflow!");

        list->head->next = NULL;
        list->head->prev = NULL;
        list->head->data = 0;

        return list;
}

void print_list(struct list_t* list)
{
        struct node_t* head = list->head;

        while (head != NULL)
        {
                printf("%d ", head->data);
                head = head->next;
        }

        printf("\n");
        return;
}

void delete_list(struct list_t* list)
{
        struct node_t* top = list->head;
	struct node_t* next;

	while (top != NULL)
	{
		next = top->next;
		free(top);
		top = next;
	}

        free(list);
}

