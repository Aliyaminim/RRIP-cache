#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node_t
{
        struct node_t* next;
        struct node_t* prev;
        int data;
};

struct node_t* add_to_list(struct node_t* bottom, int a)
{
	struct node_t* elem = calloc(1, sizeof(struct node_t));
	elem->next = NULL;
        elem->prev = bottom;
	elem->data = a;

	if (bottom != NULL)
		bottom->next = elem;
	
	return elem;
}

int main()
{
        int len = 0, n = 0, elem = 0;
        struct node_t* bottom = NULL;
        struct node_t* head = NULL;

        scanf("%d%d", &len, &n);
        scanf("%d", &elem);
        head = add_to_list(head, elem);

        for (int i = 0; i < len - 1; ++i)
        {
                scanf("%d", &elem);
                bottom = add_to_list(bottom, elem);
        }

        return 0;
}