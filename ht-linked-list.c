// deletes linked list's elements one by one
void delete_ht_linked_list(struct node_t *top)
{
    //cycling should be fixed someday... 
    
    while (top != NULL)
    {
        struct node_t *new_top = top->next;
        free(top);
        top = new_top;
    }
}


// adds element to linked list
struct node_t *add_to_ht_linked_list(struct node_t *bottom, int num)
{
    struct node_t *elem = calloc(1, sizeof(struct node_t));
    elem->next = NULL;
    elem->data = num;

    if (bottom != NULL)
    {
        bottom->next = elem;
    }

    return elem;
}

