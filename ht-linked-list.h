#pragma once

struct node_ht {
    struct node_ht *next;
    int data;
};

void delete_ht_linked_list(struct node_ht *top);

struct node_ht *add_to_ht_linked_list(struct node_ht *bottom, int num);
