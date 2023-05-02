// deletes linked list's elements one by one
void delete_ht_linked_list(struct node_ht *top)
{
    //cycling should be fixed someday... 

    while (top != NULL) {
	struct node_ht *new_top = top->next;
	free(top);
	top = new_top;
    }
}


// adds element to linked list
struct node_ht *add_to_ht_linked_list(struct node_ht *bottom, int num)
{
    struct node_ht *elem = calloc(1, sizeof(struct node_ht));
    elem->next = NULL;
    elem->data = num;

    if (bottom != NULL) {
	bottom->next = elem;
    }

    return elem;
}

